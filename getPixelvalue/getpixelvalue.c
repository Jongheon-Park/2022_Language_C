#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "BMPImage_struct.h"


RGB getPixelValue(RGB* rgb_array, int res_x, int res_y, int i, int j)
{
	// protect the run_time error
	if (i < 0)
		i += res_x;
	if (j < 0)
		j += res_y;

	i = i % res_x;
	j = j % res_y;	//if ~ j= j% res_y --> 영상처리 할때 범위 처리

	int idx = i + res_x * j;	//const 추가
	assert(idx >= 0);
	assert(idx < res_x* res_y);

	return rgb_array[idx];
}
/*
bool IsInsideCircle(int i, int j)
{
	// 반지름 30
	if ((i - 128) * (i - 128) + (j - 128) * (j - 128) - 90 * 90 < 0)
		return true;
	else
		return false;
}
*/


int main()
{

	int res_x = 0;
	int res_y = 0;
	RGB* rgb_array;
	//RGB* rgb_temp = (RGB*)malloc(sizeof(RGB) * res_x * res_y);

	readBMP24("mandrill.bmp", &res_x, &res_y, &rgb_array);
	//readBMP24("Butterfly.bmp", &res_x, &res_y, &rgb_array);

	printf("%d %d\n", res_x, res_y);

	RGB* rgb_temp = (RGB*)malloc(sizeof(RGB) * res_x * res_y);	//이미지 저장할 임시배열 생성

	//float conv_mask[3][3] = { 1, 2, 1,
	//						  2, 4, 2,
	//						  1, 2, 1 };

	float conv_mask[3][3] = { -1, -1, -1,
						   	  -1,  8, -1,
							  -1, -1, -1 };
	for (int sub_j = 0; sub_j < 9; sub_j++)
		for (int sub_i = 0; sub_i < 3; sub_i++)
		{
			conv_mask[sub_j][sub_i] /= 16.0;
		}

	for (int rep = 0; rep < 40; rep++)
	{
		for (int j = 0; j < res_y; j++)//영상
		{
			for (int i = 0; i < res_x; i++)//영상
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
				/*if (!IsInsideCircle(i, j))
				{
					int ix = i + res_x * j;
					rgb_array[ix].red =0.0;
					rgb_array[ix].green=0.0;
					rgb_array[ix].blue=0.0;
				}*/
				RGB rgb_color = { 0.0, 0.0, 0.0 };
				for (int sub_j = 0; sub_j < 3; sub_j++)//mask
				{
					for (int sub_i = 0; sub_i < 3; sub_i++)//mask
					{
						RGB color_neighbor = getPixelValue(rgb_array, res_x, res_y, i + sub_i - 1, j + sub_j - 1);
						color_neighbor.red *= conv_mask[sub_j][sub_i];
						color_neighbor.green *= conv_mask[sub_j][sub_i];
						color_neighbor.blue *= conv_mask[sub_j][sub_i];

						rgb_color.red += color_neighbor.red;
						rgb_color.green += color_neighbor.green;
						rgb_color.blue += color_neighbor.blue;
					}
				}
				rgb_temp[i + res_x * j] = rgb_color;
				//rgb_temp[i + res_x * j] = getPixelValue(rgb_array, res_x, res_y, i + res_x / 2, j + res_y / 2);

			}

		}
		for (int j = 0; j < res_y; j++)
		{
			for (int i = 0; i < res_x; i++)
			{
				rgb_array[i + res_x * j] = rgb_temp[i + res_x * j];
			}
		}
	}


	



	writeBMP24("mandrill_gray_smoothing.bmp", res_x, res_y, rgb_array);
	
	free(rgb_temp);
	
}