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
