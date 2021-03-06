// C언어 과제_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30

int main()
{
	// 학생의 이름 데이터 입력(배열 초기화 이용)
	char name[MAX][10] =
	{
		"강덕호", "고기태", "곽호철", "이도현", "박동균",
		"최동민", "한명수", "김승호", "김은미", "김태성",
		"김준형", "김민철", "박태수", "박병채", "민현우",
		"서인수", "신인규", "성재훈", "심동현", "윤승한",
		"김재박", "임기현", "이수복", "이원호", "석주명",
		"이범석", "전호진", "전광민", "조영민", "홍정모"
	};

	// 시험성적 데이터 입력(배열 초기화 이용)
	int score[MAX][5] =
	{
		{ 60, 32 },{ 11, 35 },{ 36, 19 },{ 42, 15 },{ 31, 32 },
		{ 72, 50 },{ 19, 13 },{ 50, 32 },{ 44, 20 },{ 23, 19 },
		{ 40, 26 },{ 66, 59 },{ 41, 41 },{ 40, 21 },{ 39, 45 },
		{ 68, 63 },{ 70, 82 },{ 52, 69 },{ 65, 84 },{ 31, 25 },
		{ 28, 28 },{ 30, 31 },{ 45, 90 },{ 59, 59 },{ 53, 50 },
		{ 34, 36 },{ 64, 40 },{ 41, 33 },{ 63, 45 },{ 59, 69 }
	};

	int i, j; // 반복문 사용을 위한 변수 선언
	int rep, temp; // 버블 정렬을 위한 변수 선언
	int rank[MAX]; // 석차 배열 선언
	int s_temp[MAX]; // 최종성적 버블 정렬을 위한 임의의 배열 선언
	char n_temp[MAX]; // 학생이름 버블 정렬을 위한 임의의 배열 선언
	char grade[MAX][3];
	char swap; // 플래그 변수

	
	// 최종성적 계산
	for (int i = 0; i < MAX; i++)
	{
		score[i][2] = (score[i][0] + score[i][1]) / 2;
	}

	// 이름, 최종성적, 최종석차를 최종성적순으로 정렬
	for (rep = 1; rep < MAX; rep++)
	{
		swap = 'N'; // 플래그 변수의 초기화

		for (i = 0; i < MAX - rep; i++)
		{
			if (score[i][2] < score[i + 1][2])
			{
				for (j = 0; j < 4; j++)
				{
					s_temp[i] = score[i][j];
					score[i][j] = score[i + 1][j];
					score[i + 1][j] = s_temp[i];

				}
				

				strcpy(n_temp, name[i]);
				strcpy(name[i], name[i + 1]);
				strcpy(name[i + 1], n_temp);

				swap = 'Y';
			}
			// 최종성적이 같은 경우 이름의 '가나다' 순으로 출력
			else if (score[i][2] == score[i + 1][2] && strcmp(name[i], name[i + 1]) > 0)
			{
				strcpy(n_temp, name[i]);
				strcpy(name[i], name[i + 1]);
				strcpy(name[i + 1], n_temp);

				swap = 'Y';
			}
		}
		if (swap == 'N')
			break;

		// 학생의 석차 계산
		for (i = 0; i < MAX; i++)
		{
			rank[i] = 1;

			for (j = 0; j < MAX; j++)
			{
				if (score[i][2] < score[j][2])
				{
					rank[i]++;
				}
			}
		}
	}

	// 학생의 최종성적을 상대평가로 산출
	for (int i = 0; i < MAX; i++)
	{
		if (rank[i] <= MAX * 0.1) // 최상위 10%
			strcpy(grade[i], "A+");
		else if (rank[i] <= MAX * 0.2 && rank[i] > MAX * 0.1) // 다음 10%
			strcpy(grade[i], "A");
		else if (rank[i] <= MAX * 0.4 && rank[i] > MAX * 0.2) // 다음 20%
			strcpy(grade[i], "B+");
		else if (rank[i] <= MAX * 0.6 && rank[i] > MAX * 0.4) // 다음 20%
			strcpy(grade[i], "B");
		else if (rank[i] <= MAX * 0.7 && rank[i] > MAX * 0.6) // 다음 10%
			strcpy(grade[i], "C+");
		else if (rank[i] <= MAX * 0.8 && rank[i] > MAX * 0.7) // 다음 10%
			strcpy(grade[i], "C");
		else if (rank[i] <= MAX * 0.85 && rank[i] > MAX * 0.8) // 다음 5%
			strcpy(grade[i], "D+");
		else if (rank[i] <= MAX * 0.9 && rank[i] > MAX * 0.85) // 다음 5%
			strcpy(grade[i], "D");
		else  // 다음 10%
			strcpy(grade[i], "F");
	}

	// 성적처리 프로그램 최종출력
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃              [ 과제_3 ] 성적처리 프로그램               ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	printf(" ==========================================================\n");
	printf("     이  름   중간고사   기말고사   최종성적   최종석차\n");
	printf(" ==========================================================\n");

	for (i = 0; i < MAX; i++)
	{
		printf("     %s%7d점%9d점        %s   \t   %d\n", name[i], score[i][0], score[i][1], grade[i], rank[i]);
	}
	printf(" ==========================================================\n");
	return 0;
}