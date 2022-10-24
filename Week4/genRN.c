#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<stdbool.h>

double	genRanNum(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX; //0 - 1
	temp = min + (max - min) * temp; // min - max
	return temp;
}

bool IsInsideCircle(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) - r * r;

	if (f > 0.0)
		return false;
	else
		return true;

}

void main()
{
	FILE* fp = fopen("circle.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = genRanNum(0.0, 1.0);
		double y = genRanNum(0.0, 1.0);

		if (IsInsideCircle(x, y) == true)
		{
			fprintf(fp, "%lf, %lf\n", x, y);
		}
		
	}
	fclose(fp);
	//return 0;
}