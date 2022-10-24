#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_STR 255

int main()
{
	char input_string[MAX_STR];

	scanf("%s", input_string);	//&를 안써도 되는 이유 : 주소를 나타내기 때문
	printf("%s", input_string);

	return 0;
}