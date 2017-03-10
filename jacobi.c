#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "const.h"
#include "jacobi.h"


void Jacobi_method(int row, int width, double potential[row][width],\
                   double rho[row][width]) {

  printf("Running Jacobi method\n");

  double potential_old[row][width];
  memcpy(potential_old, potential, sizeof(double)*width*row);

  for (int iteration = 1; iteration < MAXITERATION; iteration++) {
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < width - 1; j++) {
        // update new values
        potential[i][j] = (potential_old[i+1][j]+potential_old[i-1][j]+ \
                      potential_old[i][j+1]+potential_old[i][j-1]+ \
                      (4*PI)*(4*PI)*EPSILON*EPSILON*rho[i][j])/4.;
      }
    }

    // convergence criteria
    if (fabs(potential[1][1]-potential_old[1][1]) < EPSILON) {
      printf("Converge after %d iterations. Quit Jacobi method.\n", iteration);
      break;
    }

    // re-set the old potential
    memcpy(potential_old, potential, sizeof(double)*width*row);

  }

  printf("Finish running Jacobi method\n");
}
