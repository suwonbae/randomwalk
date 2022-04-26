# Random Walk

Every walk step is made, direction and size of which are either x or y and +1 and -1, respectively.

Three arguments: pbc/nopbc L steps

Either pbc (periodic boundary conditions) or nopbc can be chosen.

Boundaries: xlo = -2/L, xhi = 2/L, ylo = -2/L, yhi = 2/L

Number of steps to be made: steps


## Compiling with Makefile
```
make
```

## Running
```
./randomwalk pbc 10 1000
```
