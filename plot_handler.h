/*
 * Name: Junjie Liao
 * File: plot_handler.h
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - header file for plot_handler method
 */

#ifndef _PLOT_HANDLER_H
#define _PLOT_HANDLER_H

// pipe plotting using gnuplot
void contour_and_surface_plot_handler(int row, int width, double potential[row][width], int iteration);

#endif
