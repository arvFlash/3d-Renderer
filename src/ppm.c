#include <stdio.h>


void generate(int imageHeigth, int imageWidth, unsigned char **array)
{
  printf("P3\n%d %d\n255\n",imageWidth, imageHeigth);
  for (int j = 0; j < imageHeigth; j++) {
    for (int i = 0; i < imageWidth; i++) {
      printf("%d %d %d\n",array[j][(i * 3) + 0],
                          array[j][(i * 3) + 1], 
                          array[j][(i * 3) + 2]);
    }
  }
  return;
}
