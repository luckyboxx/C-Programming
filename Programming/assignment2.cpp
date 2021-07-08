#include "stdafx.h"
#include <stdio.h>

int main()
{
	int i, j, k;

	printf("[ 과제 2 ]\n\n");
	printf(" >>> 다음은 반복문을 이용해 별 문자 패턴 프로그램을 작성하여 출력된 화면입니다. \n\n");
	printf("(1) \n\n");

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i == 0 || i == 8 || j == 0 || j == 8)
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}

	printf("\n(2) \n\n");
	
	for (i = 1; i <= 5; i++)
	{
		for (j = (5 - i); j > 0; j--)
		{
			printf(" ");
		}
		for (k = 0; k < i; k++)
		{
			printf("*");
		}
		for (k = 0; k < (i - 1); k++)
		{
			printf("*");
		}
		for (j = (5 - i); j > 0; j--)
		{
			printf(" ");
		}

		printf("\n");
	}
	
	for (i = 1; i <= 4; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (k = (5 - i); k > 1; k--)
		{
			printf("*");
		}
		for (k = i; k < 5; k++)
		{
			printf("*");
		}
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}

		printf("\n");
	}
	printf("\n");
	
	return 0;
}
