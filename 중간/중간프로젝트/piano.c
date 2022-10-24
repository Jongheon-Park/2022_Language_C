#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<Windows.h>
#include<stdbool.h>

#define NUM_NOTES 8

char key_table[NUM_NOTES];
double freq_table[NUM_NOTES];

double getFrequency(char note)
{
	for (int i = 0; i < NUM_NOTES; i++)
	{
		if (key_table[i] == note)
			return freq_table[i];
	}
	return 0.0;
}

void initialize()
{
	FILE* fp = fopen("key_mapping.txt", "r");
	if (fp == NULL)
	{
		printf("FILE not found\n");
		exit(1);
	}

	int num_keys;
	fscanf(fp, "%d\n", &num_keys);
	printf("%d\n", num_keys);

	for (int i = 0; i < NUM_NOTES; i++)
	{
		fscanf(fp, "%c %lf\n", &key_table[i], &freq_table[i]);
	}
	fclose(fp);
}

void main()
{
	initialize();

	while (true)
	{
		char ch = getch();
		if (ch == 'x') break;
		Beep(getFrequency(ch), 500);
	}
}