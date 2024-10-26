#include "projector.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void loadedges(int **edges, FILE *file);
int projectobj(double focalLength, double **projected, int **edges) {
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
            //printf("%lf %lf %lf\n", x, y, z);
            verts++;
        } else {
            text = fgetc(obj);
            if(text != 'v' && text != '\n' && text != ' ') {
                //printf("%c\n", text);
                break;
            }
        }

    }

    loadedges(edges, obj);
    return verts;
    printf("test");
}

void loadedges(int **edges, FILE *file){
    char text;
    fseek(file, -1, SEEK_CUR);
    while(true) {
        text = fgetc(file);
        if(text == 'l')
            break;
    }
    int edge = 0;
    int i = 0;
    while(true) {
        if(fscanf(file, "%d", &edge) == 1) {
            i++;
            edges[0][i] = edge;
            //printf("edge 1: %d ", edge);
            fscanf(file, "%d", &edge);
            edges[1][i] = edge;
            //printf("edge 2: %d i: %d\n", edge, i);
        } else {
            text = fgetc(file);
            if(text != 'l' && text != '\n' && text != ' ') {
                //printf("%c\n", text);
                break;
            }
        }
        int *edge0 = realloc(edges[0], (i + 2) * sizeof(int));
        int *edge1 = realloc(edges[1], (i + 2) * sizeof(int));

        if (edge0 == NULL || edge1 == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        edges[0] = edge0;
        edges[1] = edge1;
    }
    edges[0][0] = i;
}
