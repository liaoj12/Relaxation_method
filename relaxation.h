#ifndef _RELAXATION_H
#define _RELAXATION_H

#ifndef PI
#define PI 3.14159
#endif

#ifndef MAXITERATION
#define MAXITERATION 1000
#endif

#ifndef EPSILON
#define EPSILON 0.001
#endif

// 2d print
void print_2D(int row, int width, double grid[row][width]);

// Jacobi method
void Jacobi_method(int row, int width, double grid[row][width],\
                   double rho[row][width]);

// Gauss_Seidel_method
void Gauss_Seidel_method(int row, int width, double grid[row][width],\
                         double rho[row][width]);

// over relaxation Gauss_Seidel_method
void over_Gauss_Seidel_method(int row, int width, double grid[row][width],\
                              double rho[row][width], double w);

#endif
