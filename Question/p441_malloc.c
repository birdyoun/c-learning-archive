#include <stdio.h>
#include <stdlib.h>

/*
// 1. 물품의 품명, 단가를 배열에 초기화하고, 판매한 물품 수량을 입력받아 결과 출력
// 하드디스크 = 135000, CPU = 235000, 메인보드 = 122000, 모니터 = 260000, DVD-RW = 73500
// malloc을 이용해보자. 수량을 변수로 받아서 malloc 처리할 때 인자로 sizeof랑 곱하는 식이면 맛있을 듯 ㅇㅇ
// 그러면 일단 품명, 단가는 있어야하고, 판매 물품 수량의 각 값이 malloc으로 생성되어야 함
// 값은 모든 입력 종료 후 출력

int main(void) {
	int* p = (int*)malloc(sizeof(int));
	*p = 0;
	int i = 0;
	int count[2][5]; // 0행에 카운트 받고, 1행은 카운트 단가 곱한 실값
	int pay[5] = { 135000, 235000, 122000, 260000, 73500 };
	char* item[5] = { "하드디스크", "CPU", "메인보드", "모니터", "DVD-RW" }; // 수정 안할거라 이따위로 선언해도 됨 ㅇㅇㅇㅇ

	for (i = 0; i < 5; i++) {
		printf("%s 수량 : ", item[i]);
		scanf_s("%d", &count[0][i]);
		count[1][i] = pay[i] * count[0][i];
		p = (int*)realloc(p, sizeof(int) * count[0][i]);
		*p += count[1][i];
	}

	// 출력
	printf("  물품\t\t단가\t\t수량\t\t금액\n");
	for (i = 0; i < 5; i++) {
		printf("%7s\t %7d\t %7d\t %7d원\n", item[i], pay[i], count[0][i], count[1][i]); // 한글 정렬 맞추기 포기요 
	}
	printf("\n합계 : %d", *p);

	return 0; // 뭔가 realloc을 쓸 의미가 없던거 같은데...

}
*/

/*
// 2. 주민등록번호 앞 6자리를 문자열로 입력받아, 년월일 분리 출력 + 현재 나이, 띠 출력

void print(char* a);
int true_age(char* a);
void ddi(int a);

int main(void) {
	char input[7];
	char* p = input;
	printf("주민등록번호 앞자리를 입력하시오 : ");
	scanf_s("%s", p, 7);
	while (getchar() != '\n'); // 버퍼 리셋
	printf("나이 : %d\n", true_age(p));
	print(p);

	return 0;
}

void print(char* a) {
	printf("생년, 월, 일 : ");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", *a++);
		}
		printf("\t");
	}
	printf("\n");
}

int true_age(char* a) {
	int year = ((*a - '0') * 10) + (*(a + 1) - '0'); // *10은 자릿수를 맞추기 위함 (일의자리 십의자리), '0'이 아닌 0은 주소값에 대한 연산이 됨
	// printf("%d", year); // 오류 위치 확인용
	int age = year > 26 ? 126 - year + 1 : 26 - year + 1; // 00~26 = 년도 그대로 나이, 그 외는 126 - year
	ddi(year);
	return age;
}

void ddi(int a) {
	char* name[12] = {
		"원숭이", "닭", "개", "돼지", "쥐", "소",
		"호랑이", "토끼", "용", "뱀", "말", "양"
	};
	int v = 0, di = 0;
	if (a > 26) {
		v = 1900 + a;
	}
	else {
		v = 2000 + a;
	}
	di = v % 12;
	printf("당신의 띠 : %s\n", name[di]);
}

// 근데 이러면 첫번째 실값만 나온다 어떻게 해야 두개를 다 뺄 수 있을까...
// 일단 방법1. int 형변환? 어찌되었건 저 char* 변수를 int로 만들어야한다
// 방법2. 아스키코드로 초반 두자리만 따온다 근데 이거를 어케하죠
*/

/*
훨씬 좋은 나이 로직
int current_year = 26;   // 2026년 기준 (두 자리)
int age = year > current_year ?
(100 - year) + current_year + 1 :  // 1900년대생
	current_year - year + 1;            // 2000년대생
*/

/*
// 5.int ary[][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 배열포인터 : int (*ptr)[5];
// 배열 포인터를 이용하여 다음 이차원 배열에서 모든 원소 값을 5 증가시키는 프로그램
int main(void) {
	int ary[][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 이러면 컴파일러가 자동으로 행을 나눠준다고 함. 행이 꽉 안차면 0 넣어주고
	int (*ptr)[5]; // 임마는 포인터 배열이 아닌 배열 포인터로 변수 하나임
	int i = 0, j = 0;
	ptr = ary;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 5; j++) {
			ptr[i][j] *= 5;
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d\t", ptr[i][j]);
		}

	}

	return 0;
}
*/

// 교훈 : 포인터 이전에 순수 로직 문제들 좀 더 해야겠는데? 내 전투력 지금 너무 약해요 시간이 너무 걸려
// 포인터 이전과 이후에 쓰는 주요 개념이 너무 달라서 둘 구분해서 문제들 싹 다시 하면서 머리에 딱딱 구조화할 필요가 있어보임
