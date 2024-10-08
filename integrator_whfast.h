/**
 * @file 	integrator_whfast.h
 * @brief 	Interface for numerical particle integrator
 * @author 	Hanno Rein <hanno@hanno-rein.de>
 *
 * @section 	LICENSE
 * Copyright (c) 2015 Hanno Rein, Daniel Tamayo
 *
 * This file is part of rebound.
 *
 * rebound is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rebound is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rebound.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _INTEGRATOR_WHFAST_H
#define _INTEGRATOR_WHFAST_H

#include "rebound.h"

void reb_integrator_whfast_part1(struct reb_simulation* r);		///< Internal function used to call a specific integrator
void reb_integrator_whfast_part2(struct reb_simulation* r);		///< Internal function used to call a specific integrator
void reb_integrator_whfast_synchronize(struct reb_simulation* r);	///< Internal function used to call a specific integrator
double D(struct reb_particle *p);
double kepler_solver_D_finder(const struct reb_simulation* const r, const struct reb_particle p1, const double M, double _dt);
void reb_whfast_kepler_solver(const struct reb_simulation* const r, struct reb_particle* const restrict p_j, const double M, unsigned int i, double _dt);   ///< Internal function (Main WHFast Kepler Solver)
void reb_whfast_calculate_jerk(struct reb_simulation* r);       ///< Calculates "jerk" term
int reb_integrator_whfast_init(struct reb_simulation* r);       ///< Init routine (also used by WHFast512)

#endif
