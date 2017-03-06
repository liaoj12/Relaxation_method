#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "relaxation.h"

void print_2D(int row, int width, double grid[row][width]) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < width; j++) {
      printf("%.4lf\t", grid[i][j]);
    }
    printf("\n");
  }
}

void Jacobi_method(int row, int width, double grid[row][width],\
                   double rho[row][width]) {

  printf("Running Jacobi method\n");

  double grid_old[row][width];
  memcpy(grid_old, grid, sizeof(double)*width*row);

  for (int iteration = 1; iteration < MAXITERATION; iteration++) {
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < width - 1; j++) {
        // update new values
        grid[i][j] = (grid_old[i+1][j]+grid_old[i-1][j]+ \
                      grid_old[i][j+1]+grid_old[i][j-1])/4.;
      }
    }

    // convergence criteria
    if (fabs(grid[1][1]-grid_old[1][1]) < EPSILON) {
      printf("Converge after %d iterations. Quit Jacobi method.\n", iteration);
      break;
    }

    // re-set the old grid
    memcpy(grid_old, grid, sizeof(double)*width*row);

    // print_2D(row, width, grid);
  }

  printf("Finish running Jacobi method\n");
}

void Gauss_Seidel_method(int row, int width, double grid[row][width],\
                         double rho[row][width]) {

  printf("Running Gauss-Seidel method\n");
  double compare;

  for (int iteration = 1; iteration < MAXITERATION; iteration++) {
    compare = grid[1][1];
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < width - 1; j++) {
        // update new values
        grid[i][j] = (grid[i+1][j]+grid[i-1][j]+ \
                      grid[i][j-1]+grid[i][j+1])/4.;
      }
    }

    // covergence crieria
    if (fabs(grid[1][1]-compare) < EPSILON) {
      printf("Converge after %d iterations. Quit Gauss-Seidel method.\n", iteration);
      break;
    }

    // print_2D(row, width, grid);
  }

  printf("Finish running Gauss method\n");

}

void over_Gauss_Seidel_method(int row, int width, double grid[row][width],\
                              double rho[row][width]) {

}
