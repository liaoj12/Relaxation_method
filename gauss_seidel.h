/*
 * File: gauss_seidel.h
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - header file for gauss-seidel method
 */

#ifndef _GAUSS_SEIDEL_H
#define _GAUSS_SEIDEL_H

// Gauss_Seidel_method
void Gauss_Seidel_method(int row, int width, double grid[row][width],\
                         double rho[row][width]);

#endif
