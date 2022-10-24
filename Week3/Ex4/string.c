#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	char* c = "Hello";

	printf("%s\n", c);
	printf("%p\n", c);
	printf("%p %p %p %p %p\n", &c[0], &c[1], &c[2], &c[3], &c[4]);
	printf("%c %c %c %c %c\n", c[0], c[1], c[2], c[3], c[4]);
	printf("%c %c %c %c %c\n", *c, *(c+1), *(c+2), *(c+3), *(c+4));

	return 0;
}