/*
 * File: main.c
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - file that runs the whole process
 *   - the order of the input files matter
 *
 * Command:
 *   - Compile: make
 *   - Execute: ./main boundary.txt rho.txt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "print2D.h"
#include "jacobi.h"
#include "gauss_seidel.h"
#include "over_gauss_seidel.h"


int main(int argc, char*argv[]) {

  // check if there are correct input arguments
  if (argc != 3) {
    printf("Error! Required exactly two data files as input, first as potential then charge distribution.\n");
    exit(1);
  }

  // set up to read in data from input files
  int row, width;
  FILE *fin1, *fin2;
  fin1 = fopen(argv[1], "r");
  fin2 = fopen(argv[2], "r");

  // check if the potential data file opens successfully
  if (!fin1) {
    printf("Failed to read in input file for boundary of potential. Abort!\n");
    exit(1);
  }
  // check if the charge data file opens successfully
  if (!fin2) {
    printf("Failed to read in input file for charges distribution. Abort!\n");
    exit(1);
  }

  // compare the row and width numbers in both files
  int r, w;
  fscanf(fin1, "%d %d", &row, &width);
  fscanf(fin2, "%d %d", &r, &w);

  // check if the sizes of both files matches
  if (row != r && width != w) {
    printf("Sizes of two input files don't match. Abort!\n");
    exit(1);
  } // done potential errors checking assume data is "clean"

  // read data 2d arrays for both potential and charges
  double potential[row][width], rho[row][width];

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < width; j++) {
      fscanf(fin1, "%lf", &potential[i][j]);
      fscanf(fin2, "%lf", &rho[i][j]);
    }
  }

  int option = 0;  // variable to store user's input for option
  double omega = 1.0;  // over-relaxation parameter

  // prompting user to enter a number to carry out running methods.
  printf("\n");
  printf("1. Jacobi method\n");
  printf("2. Gauss-Seidel method\n");
  printf("3. over-relaxation method\n");
  printf("Please enter a number to choose which method you want to use, and hit enter.\n");
  scanf("%d", &option);
  printf("You pick option: %d\n", option);
  switch (option) {
    case 1:
      printf("here\n");
      Jacobi_method(row, width, potential, rho);
      break;
    case 2:
      Gauss_Seidel_method(row, width, potential, rho);
      break;
    case 3:
      printf("Please enter a value for w(between 1 and 2):\n");
      scanf("%lf", &omega);
      over_Gauss_Seidel_method(row, width, potential, rho, omega);
      break;
    default:
      printf("Error! Unsuccesfully choosing a number to carry out methods.\n");
      exit(1);
  }

  // closing file pointers.
  fclose(fin1);
  fclose(fin2);

  return 0;
}
