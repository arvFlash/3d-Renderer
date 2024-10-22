#include "projector.h"

void project(double x, double y, double z, double focalLength, double** projected, int i)
{
    double projectedX = x * (focalLength / z);
    double projectedY = y * (focalLength / z);  
    projected[0][i] = projectedX;
    projected[1][i] = projectedY;
    return;
}
