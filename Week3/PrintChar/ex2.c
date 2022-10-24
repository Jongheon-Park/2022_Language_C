#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_STR 255

int main()
{
	char input_string[MAX_STR];

	scanf("%s", input_string);

	for (int i = 0; i < MAX_STR; i++)
	{
		char c = input_string[i];

		if (c == '\0')break;
	
		int ascii = (int)c;	//Çü º¯È¯

		printf("%d ", ascii);
	}

	return 0;
}