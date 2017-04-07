/*
 * Name: Junjie Liao
 * File: jacobi.c
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - file that implements Jacobi method and plot the solution as .png file
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "const.h"
#include "jacobi.h"
#include "plot_handler.h"


void Jacobi_method(int row, int width, double potential[row][width],\
                   double rho[row][width]) {

  printf("Running Jacobi method\n");

  double potential_old[row][width];  // matrix stores the old values of potential
  double max_err, err;  // maximum error; error
  // copy
  memcpy(potential_old, potential, sizeof(double)*width*row);

  // sweep out the grid
  for (int iteration = 1; iteration < MAXITERATION; iteration++) {
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < width - 1; j++) {
        // update new values
        potential[i][j] = (potential_old[i+1][j]+potential_old[i-1][j]+ \
                      potential_old[i][j+1]+potential_old[i][j-1]+ \
                      (4*PI)*rho[i][j])/4.;
      }
    }

    // convergence criteria
    max_err = 0;
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < width - 1; j++) {
        err = fabs(potential[i][j]-potential_old[i][j]);
        if (max_err < err) {
          max_err = err;
        }
      }
    }

    // successfully converged
    if (EPSILON > max_err) {
      // plot the solution and save it as a .png file
      contour_and_surface_plot_handler(row, width, potential, iteration);
      printf("Converge after %d iterations. Quit Jacobi method.\n", iteration);
      return;
    }

    // prepare potential as "old" for next iteration
    memcpy(potential_old, potential, sizeof(double)*width*row);

  } // end of iteration

  // not converge in time
  printf("Given boundary conditions don't converge with Jacobi method in time.\n");

}
