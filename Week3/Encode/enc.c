/*#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_STR 255

int main()
{
	char input_string[MAX_STR];
	

	scanf("%s", input_string);

	for (int i = 0; i < MAX_STR; i++)
	{
		char c = input_string[i];
		out_string[i] = c;

		if (c == '\0')break;

		int ascii = (int)c;
		int ascii_en = ascii - 3;//아스키 암호화
		
		if (ascii_en < 65) ascii_en += 26;
		char c_en = (char)ascii_en;
		
		out_string[i] = c_en;

	//	printf("%c", c_en);

	}
	printf("%s\n", out_string);

	for (int i = 0; i < MAX_STR; i++)
	{
		char c = out_string[i];

		if (c == '\0')break;

		int ascii = (int)c;
		int ascii_de= ascii + 3;//아스키 암호화

		if (ascii_de < 90) ascii_de -= 26;
		char c_de = (char)ascii_de;


		printf("%c", c_de);

	}

	

	return 0;
}*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_STR 255

void enc()
{
	char input_string[MAX_STR];
	printf("암호화 할 문장을 입력하시오.\n");

	scanf("%s", input_string);
	

	for (int i = 0; i < MAX_STR; i++) {//encode
		char c = input_string[i];
		if (c == '\0') break;

		int ascii = (int)c;
		int ascii_en = ascii + 3;

		if (((ascii_en >= 91) && (ascii_en <= 93)) || ((ascii_en >= 123) && (ascii_en <= 125)))
		{
			ascii_en -= 26;
		}

		char c_en = (char)ascii_en;

		printf("%c", c_en);
	}
}

void dec()
{
	char input_string[MAX_STR];
	printf("복호화 할 문장을 입력하시오.\n");

	scanf("%s", input_string);


	for (int i = 0; i < MAX_STR; i++)
	{
		char c = input_string[i];

		if (c == '\0') break;

		int ascii = (int)c;
		int ascii_de = ascii - 3;

		if (((ascii_de >= 62) && (ascii_de <= 64)) || ((ascii_de >= 94) && (ascii_de <= 96)))
		{
			ascii_de += 26;
		}

		char c_de = (char)ascii_de;

		printf("%c", c_de);
	}
}

int main()
{
	int choose;
	printf("암호화 또는 복호화 중에 하나를 고르시오.\n");
	printf("암호화와 복호화에 가능한 문자는 영문자의 대,소문자입니다.\n");
	printf("Encode----------------1\n");
	printf("Decode----------------2\n");

	scanf("%d", &choose);
	for (int i = 0; i < 99; i++)
	{
		if (choose == 1)
		{
			enc();
		}
		else if (choose == 2)
		{
			dec();
		}
		else
		{
			printf("암호화 또는 복호화 중에 하나를 고르시오\n");
			main();
		}





		return 0;
	}
}