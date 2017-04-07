/*
 * Name: Junjie Liao
 * File: over_gauss_seidel.h
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - header file for over-relaxation GS method
 */

#ifndef _OVER_GAUSS_SEIDEL_H
#define _OVER_GAUSS_SEIDEL_H

// over relaxation Gauss_Seidel_method
void over_Gauss_Seidel_method(int row, int width, double grid[row][width],\
                              double rho[row][width], double w);

#endif
