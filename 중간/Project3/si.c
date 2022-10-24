#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include<stdlib.h>
#include<string.h>
#define MAX_STR 255
//암호화 
void enc()
{
	
	FILE* fp1, * fp2;
	char sentence[MAX_STR];
	char c;

	fp1 = fopen("[exam.txt]", "r");
	fp2 = fopen("[exam_sic.txt]", "w");

	int i;
	int key = 5;
	while (fgets(sentence, MAX_STR - 1, fp1))
	{
		for (int i = 0; i < MAX_STR; i++)
		{
			char stc = sentence[i];

			if (stc == '\0') break;

			int ascii = (int)stc;
			int ascii_en = ascii + 3;

			//암호화 대소문자 xyz 
			if (((ascii_en >= 91) && (ascii_en <= 93)) || ((ascii_en >= 123) && (ascii_en <= 125)))
			{
				ascii_en -= 26;
			}

			//출력
			//char print_en = (char)ascii_en;
			//printf("%c", print_en);
			
		}
		fputs(sentence, fp2);
	}

	printf("File copy completed!\n");

	fclose(fp1);
	fclose(fp2);

	return 0;

}

//복호화 
void dec()
{
	char sentence[MAX_STR];
	printf("복호화 할 문장을 입력하시오.\n");
	scanf_s("%s", sentence, MAX_STR);

	for (int i = 0; i < MAX_STR; i++)
	{
		char stc = sentence[i];

		if (stc == '\0') break;

		int ascii = (int)stc;
		int ascii_de = ascii - 3;

		//복호화 대소문자 abc
		if (((ascii_de >= 62) && (ascii_de <= 64)) || ((ascii_de >= 94) && (ascii_de <= 96)))
		{
			ascii_de += 26;
		}

		//출력
		char print_de = (char)ascii_de;
		printf("%c", print_de);
	}
}

//함수 호출
void main()
{
	int choose;
	printf("암호화 또는, 복호화 중 하나를 고르시오.\n");
	printf("(암, 복호화 가능한 문자는 영문자 대, 소문자 입니다.)\n");
	printf("암호화------------------------ 1\n");
	printf("복호화------------------------ 2\n");
	scanf_s("%d", &choose);

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
		printf("\n암호화 또는, 복호화 중 하나를 선택하여 주십시오.\n\n");
		main();
	}
}

