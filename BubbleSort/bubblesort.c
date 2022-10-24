#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define SIZE 50

int genRanNum(double max, double min)
{
	int temp;
	temp = (int)(min + (max - min)*rand() / RAND_MAX);
	return temp;
}

int main()
{
	srand((unsigned int)time(NULL));
	int a[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		a[i] = genRanNum(100.0, 0.0);
		printf("%d ", a[i]);
		
	}
	printf("\n\n");


	//내림차순
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - -1-i; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n\n");


	//오름차순
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1 -i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}


	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}