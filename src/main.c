#include "ppm.h"
#include <stdlib.h>
#include <stdio.h>


int main() 
{
    const int rows = 255, cols = 255;
    unsigned char **array = malloc(rows * sizeof(int *));

    for(int i = 0; i < rows; i++) {
        array[i] = malloc(3 * cols * sizeof(char));
    }
    
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            if(i == j) {
                array[j][(i * 3) + 0] = 255;
                array[j][(i * 3) + 1] = 255;
                array[j][(i * 3) + 2] = 255;
            }
            else {
                array[j][(i * 3) + 0] = i;
                array[j][(i * 3) + 1] = i;
                array[j][(i * 3) + 2] = i;
            }
        }
    }
    generate(rows, cols, array);

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);    
        
    return 0;
}
