// C언어 과제.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int temp, num1, num2, sum;
	double tempF, tempC;
	char c;

	printf("화씨온도(F)를 입력하세요.: ");
	scanf_s("%d", &temp);
	getchar();
	printf("문자를 입력하세요.: ");
	scanf_s("%c", &c);
	printf("8진수 16진수를 순서대로 입력하세요.: ");
	scanf_s("%o%x", &num1, &num2);

	tempF = temp;
	tempC = (tempF - 32) / 1.8;

	sum = num1 + num2;

	printf("========================================\n");
	printf("화씨온도 %.1lf의 섭씨온도는 %.1lf입니다.\n", tempF, tempC);
	printf("%c의  ASCⅡ코드 값은 %d입니다.\n", c, c);
	printf("%o(8) + %x(16) = %d\n", num1, num2, sum);
	printf("========================================\n");

	return 0;
}