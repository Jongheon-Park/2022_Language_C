#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "BMPImage_st.h"


RGB getPixelValue(RGB* rgb_array, int res_x, int res_y, int i, int j)
{
	// protect the run_time error
	if (i < 0)
		i += res_x;
	if (j < 0)
		j += res_y;

	i = i % res_x;
	j = j % res_y;	//if ~ j= j% res_y --> 영상처리 할때 범위 처리

	const int idx = i + res_x * j;	//const 추가
	assert(idx >= 0);
	assert(idx < res_x* res_y);

	return rgb_array[idx];
}



int main()
{

	int res_x = 0;
	int res_y = 0;
	RGB* rgb_array;


	readBMP24("mandrill.bmp", &res_x, &res_y, &rgb_array);
	

	printf("%d %d\n", res_x, res_y);

	RGB* rgb_temp = (RGB*)malloc(sizeof(RGB) * res_x * res_y);

	
	float conv_mask[3][3] = { -1., -1, -1,
							  -1,  8, -1,
							  -1, -1, -1 };
	for (int sub = 0; sub < 9; sub++)
	{
		(&conv_mask[0][0])[sub] /= 16.0f;
	}
	
	//color-->gray
	for (int j = 0; j < res_y; j++)
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
		}
	}
		
	for (int j = 0; j < res_y; j++)
	{
		for (int i = 0; i < res_x; i++)
		{
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
	writeBMP24("mandrill_gray_detection.bmp", res_x, res_y, rgb_array);
	free(rgb_temp);

}