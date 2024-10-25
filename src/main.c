#include "ppm.h"
#include <stdlib.h>
#include <stdio.h>
#include "projector.h"
#include "obj.h"
int main()
{
    double focalLength = 350;
    const int width = 1500, heigth = 1500;
    unsigned char ***array = malloc(width * sizeof(char **));

    for(int i = 0; i < width; i++) {
        array[i] = malloc(heigth * sizeof(char *));
    }
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < heigth; j++) {
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
    verts = projectobj(focalLength, projected);


    for(int i = 0; i < verts; i++) {
        if (projected[0][i] + (int)(width / 2) <= width - 1 && projected[1][i] + (int)(heigth / 2) <= heigth - 1 && projected[0][i] + (int)(width / 2) >= 0 && projected[1][i] + (int)(heigth / 2) >= 0){
            array[(int)projected[0][i] + (width / 2)][(int)projected[1][i] + (heigth / 2)][0] = 255;
            array[(int)projected[0][i] + (width / 2)][(int)projected[1][i] + (heigth / 2)][1] = 255;
            array[(int)projected[0][i] + (width / 2)][(int)projected[1][i] + (heigth / 2)][2] = 255;
            //printf("%d %d %d\n", i, (int)projected[0][i] + (width / 2), (int)projected[1][i] + (heigth / 2));
            //printf("array value: %d \n", array[(int)projected[0][i] + (width / 2)][(int)projected[1][i] + (heigth / 2)][0]);
        }
    }

    line((int)projected[0][1] + (width / 2), (int)projected[1][1] + (heigth / 2),(int)projected[0][2] + (width / 2), (int)projected[1][2] + (heigth / 2), array);
    generate(width, heigth, array);

    for (int i = 0; i < width; i++) {
        for(int j = 0; j < heigth; j++) {
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
