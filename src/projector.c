#include "projector.h"
#include <stdlib.h>
#include <stdio.h>

void project(double x, double y, double z, double focalLength, double** projected, int i) {
    double zoom = 100;
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

void linelow(int x1, int y1, int x2, int y2, unsigned char ***array) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int yi = 1;
    if(dy < 0) {
        yi = -1;
        dy = 0 - dy;
    }
    int D = (2 * dy) - dx;
    int y = y1;

    for(int x = x1; x <= x2; x++) {
        //printf("1 x: %d , y: %d\n", x, y);
        array[x][y][0] = 255;
        array[x][y][1] = 255;
        array[x][y][2] = 255;
        if(D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        } else {
            D = D + 2 * dy;
        }
    }
}

void linehigh(int x1, int x2, int y1, int y2, unsigned char ***array) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int xi = 1;
    if(dx < 0) {
        xi = -1;
        dx = 0 - dx;
    }
    int D = (2 * dx) - dy;
    int x = x1;

    for(int y = y1; y <= y2; y++) {
        //printf("2 x: %d , y: %d\n", x, y);
        array[x][y][0] = 255;
        array[x][y][1] = 255;
        array[x][y][2] = 255;
        if(D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        } else {
            D = D + 2 * dx;
        }
    }
}

void line(int x1, int y1, int x2, int y2, unsigned char ***array)
{
    if(abs(y2 - y1) < abs(x2 - x1)) {
        if(x1 > x2)
            linelow(x2, y2, x1, y1, array);
        else
            linelow(x1, y1, x2, y2, array);

    } else {
        if(y1 > y2)
            linehigh(x2, y2, x1, y1, array);
        else
            linehigh(x1, y1, x2, y2, array);
    }
}
