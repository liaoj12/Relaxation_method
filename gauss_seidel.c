/*
 * Name: Junjie Liao
 * File: gauss_seidel.c
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - file that implments Gauss-Seidel method
 */

#include "const.h"
#include "gauss_seidel.h"
#include "over_gauss_seidel.h"

void Gauss_Seidel_method(int row, int width, double potential[row][width],\
                         double rho[row][width]) {

  over_Gauss_Seidel_method(row, width, potential, rho, 1);
}
