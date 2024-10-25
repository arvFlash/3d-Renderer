#include <stdio.h>



void generate(int imageWidth, int imageHeigth, unsigned char ***array)
{
    FILE *file;
    file = fopen("image.ppm", "w");
    fprintf(file, "P3\n%d %d\n255\n",imageWidth, imageHeigth);
    for (int j = 0; j < imageHeigth; j++) {
        for (int i = 0; i < imageWidth; i++) {
            fprintf(file, "%d %d %d\n",array[i][j][0],
                                       array[i][j][1],
                                       array[i][j][2]);

        }
    }
    fclose(file);
    return;
}
