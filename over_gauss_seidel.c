/*
 * File: over_gauss_seidel.c
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - file that implements the over-relaxation GS method;
 *     and plot the solution as .png file
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "const.h"
#include "over_gauss_seidel.h"
#include "plot_handler.h"

void over_Gauss_Seidel_method(int row, int width, double potential[row][width],\
                              double rho[row][width], double w) {

  // check if w=1
  if (w != 1) {
    printf("Running over relaxed Gauss-Seidel method with w = %lf.\n", w);
  } else {
    printf("Running Gauss-Seidel method.\n");
  }

  // maximum error; error; and old value of a single cell
  double max_err, err, old_val;

  // sweep out the grid
  for (int iteration = 1; iteration < MAXITERATION; iteration++) {
    // reinitilize maximum error at each iteration
    max_err = 0;
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < width - 1; j++) {
        old_val = potential[i][j];
        // update new values
        potential[i][j] = (1-w)*potential[i][j] + (w/4)*(potential[i+1][j]+potential[i-1][j]+ \
                                           potential[i][j-1]+potential[i][j+1]+ \
                     (4*PI)*rho[i][j]);

        // find max_err
        err = fabs(potential[i][j] - old_val);
        if (max_err < err) {
          max_err = err;
        }
      }
    }

    // covergence crieria
    if (max_err < EPSILON) {
      // plot the solution and save it as .png file
      contour_and_surface_plot_handler(row, width, potential, iteration);
      printf("Converge after %d iterations. Quit Gauss-Seidel method.\n", iteration);
      return;
    }
  }

  // not converge in time
  printf("Given boundary conditions doesn't converge with over relaxed Gauss-Seidel method in time.\n");
}
