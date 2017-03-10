#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "const.h"
#include "over_gauss_seidel.h"

void over_Gauss_Seidel_method(int row, int width, double potential[row][width],\
                              double rho[row][width], double w) {

  printf("Running over relax Gauss-Seidel method\n");
  double compare;

  for (int iteration = 1; iteration < MAXITERATION; iteration++) {
    compare = potential[1][1];
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < width - 1; j++) {
        // update new values
        potential[i][j] = (1-w)*potential[i][j] + w*(potential[i+1][j]+potential[i-1][j]+ \
                                           potential[i][j-1]+potential[i][j+1]+ \
                     (4*PI)*(4*PI)*EPSILON*EPSILON*rho[i][j])/4.;
      }
    }

    // covergence crieria
    if (fabs(potential[1][1]-compare) < EPSILON) {
      printf("Converge after %d iterations. Quit Gauss-Seidel method.\n", iteration);
      break;
    }

  }
}
