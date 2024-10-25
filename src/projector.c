#include "projector.h"
#include <stdlib.h>
#include <stdio.h>

void project(double x, double y, double z, double focalLength, double** projected, int i) {
    double zoom = 10;
    double movx = 0;
    double movy = 0;
    double movz = -100;
    x += movx;
    y += movy;
    z += movz;
    double projectedX = (x * (focalLength / z)) * zoom;
    double projectedY = (y * (focalLength / z)) * zoom;

    double* newProjectedX = realloc(projected[0], (i + 1) * sizeof(double));
    double* newProjectedY = realloc(projected[1], (i + 1) * sizeof(double));

    // Check if realloc succeeded
    if (newProjectedX == NULL || newProjectedY == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);  // Exit if memory allocation fails
    }

    projected[0] = newProjectedX;
    projected[1] = newProjectedY;


    projected[0][i] = projectedX;
    projected[1][i] = projectedY;

    //printf("Projected X: %lf, Projected Y: %lf\n", projectedX, projectedY);

}

void line(int x1, int y1, int x2, int y2, unsigned char ***array)
{

}
