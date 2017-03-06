#include <stdio.h>
#include <string.h>
#include "relaxation.h"


int main(int argc, char const *argv[]) {

  int row = 6, width =7;
  double grid[row][width], rho[row][width];

  memset(rho, 0, sizeof(double)*width*row);
  memset(grid, 0, sizeof(double)*width*row);

  int head = 1, begin = 1;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < width; j++) {
      if (head == 1) {
        grid[i][j] = 1;
      }
      else {
        if (begin == 1){
          grid[i][j] = 1;
          begin = 0;
        }
      }
    }
    if(head == 1) {
      head = 2;
    }
    begin = 1;
  }


  Jacobi_method(row, width, grid, rho);
  printf("grid after jacobi method\n");


  // Gauss_Seidel_method(row, width, grid, rho);
  // printf("print 2d after Gauss-Seidel method\n");
  print_2D(row, width,  grid);

  return 0;
}
