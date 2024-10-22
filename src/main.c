#include "ppm.h"
#include <stdlib.h>
#include <stdio.h>
#include "projector.h"

int main()
{
    double focalLength = 350;
    const int rows = 1000, cols = 1000;
    unsigned char ***array = malloc(rows * sizeof(char **));

    for(int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(char *));
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i][j] = malloc(3 * sizeof(char));
            array[i][j][0] = 0;
            array[i][j][1] = 0;
            array[i][j][2] = 0;
        }
    }
    double **projected = malloc(2 * sizeof(int*));
    projected[0] = malloc(1 * sizeof(double));
    projected[1] = malloc(1 * sizeof(double));
    int verts = 0;



    project( 50,  50,  50, focalLength, projected, 0);
    verts++;
    project( 50, -50,  50, focalLength, projected, 1);
    verts++;
    project(-50, -50,  50, focalLength, projected, 2);
    verts++;
    project(-50,  50,  50, focalLength, projected, 3);
    verts++;
    project( 50,  50, -50, focalLength, projected, 4);
    verts++;
    project( 50, -50, -50, focalLength, projected, 5);
    verts++;
    project(-50, -50, -50, focalLength, projected, 6);
    verts++;
    project(-50,  50, -50, focalLength, projected, 7);
    verts++;


    for(int i = 0; i < verts; i++) {
        if (projected[0][i] + (int)(cols / 2) <= cols - 1 && projected[1][i] + (int)(rows / 2) <= rows - 1 && projected[0][i] + (int)(cols / 2) >= 0 && projected[1][i] + (int)(rows / 2) >= 0){
            array[(int)projected[1][i] + (rows / 2)][(int)projected[0][i] + (cols / 2)][0] = 255;
            array[(int)projected[1][i] + (rows / 2)][(int)projected[0][i] + (cols / 2)][1] = 255;
            array[(int)projected[1][i] + (rows / 2)][(int)projected[0][i] + (cols / 2)][2] = 255;
            //printf("%d %f %f\n", i, projected[0][i], projected[1][i]);

        }
    }


    generate(rows, cols, array);

    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
    free(projected[0]);
    free(projected[1]);
    free(projected);
    return 0;
}
