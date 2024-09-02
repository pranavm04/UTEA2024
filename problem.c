#include <stdio.h>
#include <stdlib.h>
#include "rebound.h"
#include "integrator_whfast.h"

#define PI 3.14159265358979323846
#define T_TOLERANCE 1e-14
#define MAX_ITERS 100

int main(int argc, char* argv[]) {
    struct reb_simulation *r = reb_simulation_create();

    /* SET INTEGRATOR PARAMETERS HERE */

    // ADDING PARTICLES
    reb_simulation_add_fmt(r, "m", 1.0);
    reb_simulation_add_fmt(r, "m a e", 1e-5, 1.0, 0.1);
    reb_simulation_add_fmt(r, "m a", 1e-5, 1.757);

    // INTEGRATOR PARAMETERS
    r->integrator = REB_INTEGRATOR_WHFAST;
    r->dt = 0.05812381638589003;
    double total_time = 1095;

    // FILE TO STORE RESULTS
    FILE *fptr = fopen("ttvdata_kepler.txt", "a");

    /* END OF INTEGRATOR PARAMETERS */


    printf("Starting sim\n");

    if (fptr == NULL) exit(1);

    struct reb_particle *p = r->particles;
    double time = 0;
    struct reb_orbit o = reb_orbit_from_particle(r->G, p[1], p[0]);
    double timestep = 0.08 * o.P;

    reb_simulation_move_to_hel(r);
    double D_old = (p[1].y * p[1].vy) + (p[1].z * p[1].vz);
    reb_simulation_move_to_com(r);
    double t_old = 0;

    double D_new, t_new;
    double D_temp, t_temp;
    int iters = 0;

    do {
        time += timestep;
        reb_simulation_integrate(r, time);
        reb_simulation_move_to_hel(r);
        D_new = D(p);
        reb_simulation_move_to_com(r);
        t_new = r->t;

        if (D_old * D_new <= 0 && p[1].x > 0)             // check that transit occured in this timestep
        {
            // bisection
            iters = 0;
            while (t_new - t_old > T_TOLERANCE && p[1].x > 0 && iters < MAX_ITERS) {
                iters++;
                t_temp = (t_new + t_old) / 2.0;
                reb_simulation_integrate(r, t_old);
                reb_simulation_move_to_hel(r);
                D_temp = kepler_solver_D_finder(r, p[1], p[0].m / r->G, t_temp - t_old);
                reb_simulation_move_to_com(r);

                if (D_old * D_temp <= 0) {
                    D_new = D_temp;
                    t_new = t_temp;
                } else {
                    D_old = D_temp;
                    t_old = t_temp;
                }
            }
            if (p[1].x > 0) fprintf(fptr, "%.15f,", (t_old + t_new)/2.0);
        }
        t_old = t_new;
        D_old = D_new;
    }
    while (time < total_time);

    printf("Finished\n");

    // FREE MEMORY
    fclose(fptr);
    reb_simulation_free(r);
}