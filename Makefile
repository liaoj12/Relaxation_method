# define object files
OBJECTS = \
main.o \
jacobi.o \
gauss_seidel.o \
over_gauss_seidel.o \
print2D.o \
plot_handler.o

# define comiler and its flags
CC = gcc
CFLAGS = -Wall -O -g

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

# Remove all object files and programme executables
clean:
	rm -f *.o *.O *.png main
