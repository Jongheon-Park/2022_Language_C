#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "BMPImage.h"



int main()
{
		
	int res_x = 0;
	int res_y = 0;
	RGB* rgb_array;

	readBMP24("Butterfly.bmp", &res_x, &res_y, &rgb_array);
	//readBMP24("Butterfly.bmp", &res_x, &res_y, &rgb_array);

	printf("%d %d\n", res_x, res_y);

	for (int j = res_y-1; j >=0 ; j--)
	{
		for (int i = 0; i < res_x; i++)
		{
			float r, g, b, gray;
			int ix = i + res_x * j;
			r = rgb_array[ix].red;
			g = rgb_array[ix].green;
			b = rgb_array[ix].blue;

			gray = (r + g + b) / 3;

			rgb_array[ix].red = gray;
			rgb_array[ix].green = gray;
			rgb_array[ix].blue = gray;

			/*
			if (r == 255 && g == 255 && b == 255)
			{
				printf(" ");
				rgb_array[ix].red = 0;
			}
			else
			{
				printf("x");
			}*/
		}
		printf("\n");
	}
	writeBMP24("gray_but.bmp", res_x, res_y, rgb_array);
}