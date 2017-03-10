#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "print2D.h"
#include "jacobi.h"
#include "gauss_seidel.h"
#include "over_gauss_seidel.h"


int main(int argc, char const *argv[]) {

  int row, width;
  FILE *fin1, *fin2;
  fin1 = fopen("potential.txt", "r");
  fin2 = fopen("charges.txt", "r");

  if (!fin1) {
    printf("Failed to read in input file for potential. Abort!\n");
    exit(1);
  }
  if (!fin2) {
    printf("Failed to read in input file for charges. Abort!\n");
    exit(1);
  }

  int r, w;
  fscanf(fin1, "%d %d", &row, &width);
  fscanf(fin2, "%d %d", &r, &w);

  if (row != r && width != w) {
    printf("Sizes of two input files don't match. Abort!\n");
    exit(1);
  }

  // done potential error checking
  // could keep checking if readin data is clean, but lazy here
  // and just assume it's fine

  // set up 2d arrays for both potential and charges
  double potential[row][width], rho[row][width];

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < width; j++) {
      fscanf(fin1, "%lf", &potential[i][j]);
      fscanf(fin2, "%lf", &rho[i][j]);
    }
  }

  // Jacobi_method(row, width, potential, rho);
  // printf("potential after jacobi method\n");

  // Gauss_Seidel_method(row, width, potential, rho);
  // printf("print 2d after Gauss-Seidel method\n");

  over_Gauss_Seidel_method(row, width, potential, rho, 1.5);
  printf("print 2d after over Gauss-Seidel method\n");

  print_2D(row, width, potential);

  fclose(fin1);
  fclose(fin2);

  return 0;
}
