/*
 * File: plot_handler.c
 * Created: Mar 04 2017
 * Last Modified: Apr 06 2017
 *
 * Comment:
 *   - file that implements the method of plot_handler
 */

#include <stdio.h>
#include <stdlib.h>
#include "plot_handler.h"

// do contour and surface plot
void contour_and_surface_plot_handler(int row, int width, double potential[row][width], int iteration) {

  // initialize a pointer for piping between gnuplot and C
  FILE *gnuplotPipe;
  gnuplotPipe = popen("gnuplot -persist","w");

  // check if it opens successfully
  if (gnuplotPipe) {
    // set up plotting parameters
    fprintf(gnuplotPipe, "set terminal png\n");  // output as a .png file
    fprintf(gnuplotPipe, "set output 'plot-%07d.png'\n", iteration);
    fprintf(gnuplotPipe, "set xlabel 'i'\n");
    fprintf(gnuplotPipe, "set ylabel 'j'\n");
    fprintf(gnuplotPipe, "set zlabel 'V'\n");
    fprintf(gnuplotPipe, "set xrange [:%d]\n", row);
    fprintf(gnuplotPipe, "set yrange [:%d] reverse nowriteback\n", width);
    fprintf(gnuplotPipe, "set key at screen 1, 0.9, 0 right top vertical Right noreverse enhanced nobox\n");
    fprintf(gnuplotPipe, "set style textbox opaque noborder margins 0.5, 0.5\n");
    fprintf(gnuplotPipe, "set contour both\n");
    fprintf(gnuplotPipe, "set title 'solution of potential after %d iteration'\n", iteration);
    fprintf(gnuplotPipe, "splot '-' title 'plot matrix' w l\n");
    // plot each value in the cell
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < width; j++) {
        fprintf(gnuplotPipe, "%d %d %g\n", i, j, potential[i][j]);
      }
      fprintf(gnuplotPipe, "\n");
    }
    // execute gnuplot commands from pipe
    fflush(gnuplotPipe);
    fprintf(gnuplotPipe, "e\n");
    fprintf(gnuplotPipe, "exit\n");
  } else {
    // case that no gnuplot
    printf("gnuplot not found...");
  }

  // close pipe pointer
  pclose(gnuplotPipe);
}
