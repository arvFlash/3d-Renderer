#include "projector.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int projectobj(double focalLength, double **projected) {
    FILE *obj;
    int verts = 0;
    obj = fopen("model.obj", "r");
    if(obj == NULL)
        return 0;
    //printf("%p", obj);
    int i = 0;
    char text;
    while(true) {
        text = fgetc(obj);
        if(text == 'v')
            break;
    }
    while(true) {
        double x, y, z;
        if(fscanf(obj, "%lf", &x) == 1) {
            fscanf(obj, "%lf", &y);
            fscanf(obj, "%lf", &z);
            project(x, y, z, focalLength, projected, verts);
            printf("%lf %lf %lf\n", x, y, z);
            verts++;
        } else {
            text = fgetc(obj);
            if(text != 'v' && text != '\n' && text != ' ') {
                printf("%c\n", text);
                break;
            }
        }

    }
    return verts;
    printf("test");
}
