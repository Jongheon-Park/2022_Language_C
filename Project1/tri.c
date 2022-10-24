#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getRandomNumber(double, double);
bool Righttriangle1(double, double);
bool Righttriangle2(double, double);



int main()
{

	FILE* fp = fopen("triangle.txt", "w");


	srand((unsigned int)time(NULL)); //매번 다른 seed 값 생성

	for (int i = 0; i < 10000; i++)
	{

		double x = getRandomNumber(0.0, 2.0);
		double y = getRandomNumber(0.0, 2.0);



		if (Righttriangle1(x, y) == true)
			fprintf(fp, "%f, %f\n", x, y);

	}

	for (int j = 0; j < 10000; j++)
	{

		double x = getRandomNumber(0.0, 2.0);
		double y = getRandomNumber(0.0, 2.0);



		if (Righttriangle2(x, y) == true)
			fprintf(fp, "%f, %f\n", x, y);

	}

	fclose(fp);
	return 0;
}

double getRandomNumber(double min, double max)
{
	double temp = (double)rand() / (double)RAND_MAX; // 0 <= temp <= 2
	temp = min + (max - min) * temp;

	return temp;
}


bool Righttriangle1(double x, double y)
{
	double x_t = 0;
	double y_t = 0;


	x_t >= 0 && x_t <= 1;
	y_t = 2 * x_t;

	double f_val = ((x - x_t) * (y - y_t)) / 2;
	if (f_val > 0.0)
		return false;
	else
		return true;
}


bool Righttriangle2(double x, double y)
{
	double x_t = 0;
	double y_t = 0;


	x_t >= 1 && x_t <= 2;
	y_t = (-2 * x_t) + 4;

	double f_val = ((x - x_t) * (y - y_t)) / 2;
	if (f_val > 0.0)
		return false;
	else
		return true;
}