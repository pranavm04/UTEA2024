# UTEA2024

In this repository is the code I worked on as a student researcher with Professor Hanno Rein.

The files include the problem.c file, and 2 REBOUND source code files modified to include the functions needed for problem.c

To run the program, the files "integrator_whfast.h" and "integrator_whfast.c" in REBOUND need to be replaced with the files provided in this repo.

The total time to integrate, integration timestep, and parameters for the star and planets can be modified in problem.c

This program implements the TTVFast algorithm (Deck et al., 2014) using the WHFAST integrator within REBOUND.


# REFERENCES:

1. Katherine M. Deck, Eric Agol, Matthew J. Holman, and David Nesvorný, TTVFast: AN EFFICIENT AND ACCURATE CODE FOR TRANSIT TIMING INVERSION PROBLEMS, The Astrophysical Journal, Volume 787, Number 2, 12 May 2014, https://doi.org/10.48550/arXiv.1403.1895
2. Hanno Rein, Daniel Tamayo, whfast: a fast and unbiased implementation of a symplectic Wisdom–Holman integrator for long-term gravitational simulations, Monthly Notices of the Royal Astronomical Society, Volume 452, Issue 1, 01 September 2015, https://doi.org/10.1093/mnras/stv1257
