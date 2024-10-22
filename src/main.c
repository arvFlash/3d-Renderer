#include "ppm.h"
#include <stdlib.h>
#include <stdio.h>
#include "projector.h"

int main() 
{
    double focalLength = 350;
    const int rows = 1000, cols = 1000;
    unsigned char **array = malloc(rows * sizeof(int *));

    for(int i = 0; i < rows; i++) {
        array[i] = malloc(3 * cols * sizeof(char));
    }
    double **projected = malloc(2 * sizeof(int*));
    projected[0] = malloc(100 * sizeof(double));
    projected[1] = malloc(100 * sizeof(double));
    
    project(23, 63, 85, focalLength, projected, 0);
    if (projected[0][0] <= cols && projected[1][0] <= rows) {
        array[(int)projected[1][0]][((int)projected[0][0] * 3) + 0] = 255;
        array[(int)projected[1][0]][((int)projected[0][0] * 3) + 1] = 255;
        array[(int)projected[1][0]][((int)projected[0][0] * 3) + 2] = 255;

    }

    generate(rows, cols, array);

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);    
        
    return 0;
}
