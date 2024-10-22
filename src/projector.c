#include "projector.h"
#include <stdlib.h>
#include <stdio.h>

void project(double x, double y, double z, double focalLength, double** projected, int i) {
    double zoom = 1;
    double projectedX = (x * (focalLength / z)) * zoom;
    double projectedY = (y * (focalLength / z)) * zoom;

    // Ensure there is enough space for the new projection
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

    // De
}
