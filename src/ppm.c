#include <stdio.h>

void line(int x, int y, unsigned char ***array)
{


}

void generate(int imageWidth, int imageHeigth, unsigned char ***array)
{
  printf("P3\n%d %d\n255\n",imageWidth, imageHeigth);
  for (int j = 0; j < imageWidth; j++) {
    for (int i = 0; i < imageHeigth; i++) {
      printf("%d %d %d\n",array[j][i][0],
                          array[j][i][1],
                          array[j][i][2]);
    }
  }
  return;
}
