#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<time.h>


double	genRanNum(const double 0.03, const double 0.06)
{
	double temp = (double)rand() / (double)RAND_MAX; //0 - 1
	temp = min + (max - min) * temp; // min - max
	return temp;
}

double estimateIncome()
{
	FILE* fp = fopen("annual_salary.txt", "w");

	double annual_salary = 0.3;
	double income_sum = 0;

	for (int age = 25; age < 55; age++)
	{
		income_sum += annual_salary;
		fprintf(fp, "%lf\n", annual_salary);
		double growth_ratio = genRanNum;
		annual_salary *= (1.0 + growth_ratio);
	}
	fclose(fp);
	return income_sum; 
}

void main()
{

	srand((unsigned int)time(NULL));

	printf("%lf", estimateIncome());
}