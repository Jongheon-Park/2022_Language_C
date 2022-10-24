#include<stdio.h>

// 0 1 1 2 3 5 8 13 21 ---------

int Fibbo(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;

	else
		return(Fibbo(num - 1)+ Fibbo(num-2));
}

int main()
{

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", Fibbo(i));
	}






}