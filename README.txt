This C program allows one to use Jacobi method, Gauss-Seidel method and its variant over-relaxation Gauss-Seidel method to solve a 2D Poisson equation.

There also is a module print2D method which allows one to output solution in terminal as option if one finds it useful, for example in debugging for future use.

How to build:
cd to the directory where the makefile is at and run:
make

How to use:
run:
./main potential.txt rho.txt

Where potential.txt is the input file of the potential V(boundary conditions), and rho.txt is the input file for charge distribution.
Both input files need to have the same size.

The charge distribution, one can split a single charge into 4 equally smaller charges just in case the row number and the width number are odd.

Option:
run:
make clean

This command will clean up all the generated files from compiler and delete all generated .png files in the directory.
