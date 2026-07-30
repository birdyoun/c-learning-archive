#include <stdio.h>
#include <stdlib.h>
#include "mymac.h"

void hakjum();
void mulandhap();
void toupper();
void inch();

// 문제별로 나눠서 전체 주석 안쳐도 되게 만들기
int main(void) {
	// hakjum(); // 1
	// mulandhap(); // 2
	// toupper(); // 3
	// printf("\n%d", DIV(4, 2)); // 7. 헤더에 매크로 넣어서 두 수의 나누기 실행해보기
	// printf("\n%d", MUL(4, 2)); // 8. 매크로로 곱셈 구현
	// printf("\n%d", SQ2(SQ2(3))); // 9. #define SQ2(x) (x*x) 이 매크로를 이용해 3의 네제곱 구하기
	// inch(); // 10

	return 0;
}

// 1. 학점 구하기
void hakjum() {
	char a;

	printf("이번 학기에 수강하는 총 학점은 ???? : "); // 하나에 3학점이라고 퉁쳐퉁쳐잇
	a = getch(); // 문자 입력으로 들어가서 1~9는 아스키 값이 들어가게 됨. 이거 변환해야됨!!!!!!
	printf("총 %d학점", (a - '0') * 3);
}
// 기본 조작

// 2. 숫자 입력받아 곱 플 계산
void mulandhap() {
	int x = 0, y = 0;

	printf("\n한자리수 정수 두 개를 입력하시오 : ");
	x = (getche() - '0'); // 입력을 볼 수 있게
	y = (getche() - '0');
	printf("\n곱 : %d, 합 : %d", x * y, x + y);
}
// 문자의 숫자로 형변환

// 3. 문자 입력받아서 대문자로 바꾸기
void toupper() {
	char a;

	printf("\n영어 입력하세요: ");
	a = getchar();

	if (a > 97 && a < 122) { // 소문자 맞으면
		a = a - 'a' + 'A';
		printf("\n대문자 : %c ", a);
	}
	else {
		printf("\n소문자를 입력하세요...");
	}
}
// 아스키 이용

// 10. 센티미터 정수로 받아서 인치로 바꾼뒤 소수로 출력하기
void inch() {
	int cm = 0;

	printf("\n센티미터 입력하세요 : ");
	cm = (getchar() - '0'); // 이거 좀 똑똑한듯? ㅋㅋ
	printf("\n인치로 바꾸면 : %f", cm / 2.54);
}
