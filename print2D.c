/*
 * File: print2D.c
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - file that implements the print_2D method
 */

#include <stdio.h>
#include "print2D.h"

void print_2D(int row, int width, double potential[row][width]) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < width; j++) {
      printf("%.4lf\t", potential[i][j]);
    }
    printf("\n");
  }
}
