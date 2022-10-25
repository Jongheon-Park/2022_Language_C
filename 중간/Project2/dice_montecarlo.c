#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getRanNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX; // 0 ~ 1
	temp = min + (max - min) * temp; // min ~ max
	return temp;
}

/*bool dice(const double x, const double y)
{

	if (x >= 0.0 && x <= 1.0 && 2 * x <= y) {
		return true;
	}


	if (x >= 1.0 && x <= 2.0 && -2 * x + 4 <= y) {
		return true;
	}
	return false;

}*/

void main()
{
	FILE* fp = fopen("tr_mo.txt", "w");
	srand((unsigned int)time(NULL));
	int dice[6];

	for (int trials = 100; trials < 100000; trials*=2)
	{
		for(int i=0; i<6; i++)
		{
			dice[i]=0;
		}
		for (int i = 0; i < num_dice; i++)
		{
			int num = (int)getRanNumber(0.0, 6.0);
			dice[num]++;
		}
		for(int j = 0; j<6; j++)
		{
		const double area = dice[j] / trails; //구해진 값이 1/6
		}
		printf("Estimated pi by MonCarlo Simulation = %lf\n", area);

		fprintf(fp, "%lf\n", area);
	}

	fclose(fp);
}