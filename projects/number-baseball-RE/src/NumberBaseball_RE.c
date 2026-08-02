#include <stdio.h>
#include <string.h>
#include "NumberBaseball_RE.h"
#define SIZE 4

static int check_ball(char ball[SIZE], char* my_ball);
static int check_input(char* my_ball);
static void win();
static void lose();

void play_baseball(char ball[SIZE]) {
	char my_ball[5] = {0};
	char* p = my_ball;
	
	for (int i = 0; i < 9; i++) {
		printf("%d회차입니다. 숫자를 입력하세요 : ", i + 1);
		scanf_s("%s", p, SIZE + 1);
		while (getchar() != '\n');

		if (check_input(p)) { // 1이 리턴되어 정상 입력임이 확인된 경우에 check_ball 실행
			if (check_ball(ball, p)) { // 4스트라이크 달성한 경우 win 호출 후 현재 함수 즉시 종료
				win();
				return;
			}
		}
		else { // 정상 입력이 아닌 경우 i의 증가를 캔슬하고 다시 반복 실행
			i--;
		}
	}

	lose(); // for의 종료로 win에 도달하지 못한 경우 패배 처리
}


int check_ball(char ball[SIZE], char* my_ball) { // 4스트라이크시 1을 리턴, 아닌 경우 0을 리턴
	int s = 0, b = 0, o = 0; // 각각 스트라이크, 볼, 아웃
	int ball_counter = 0;

	for (int j = 0; j < SIZE; j++) { // 스트라이크만 먼저 루프로 확인, 볼, 아웃과 반복 구분한 이유는 세개를 동시에 판별하면 너무 더러워짐
		if (ball[j] == my_ball[j]) {
			s++;
		}
	}

	if (s == SIZE) { 
		return 1; // 4스트라이크시 즉시 리턴하여 하단 코드가 실행 안되게 함
	}
	else {
		for (int x = 0; x < SIZE; x++) {
			if (ball[x] == my_ball[x]) { // 위의 반복에서 스트라이크로 판별된 곳은 무시*
				continue;
			}

			for (int y = 0; y < SIZE; y++) { // 앞의 값도 계속 확인해줘야해서 반복 조건을 이렇게 지정함
				if (x == y) { // 같은 인덱스끼리의 비교는 의미없으므로 스킵*
					continue;
				}
				else if (my_ball[x] == ball[y]) {
					ball_counter++;
					break;
				}
			}

			if (ball_counter != 0) {
				b++;
			}
			else {
				o++;
			}
			ball_counter = 0;
		}
	}

	printf("%d스트라이크\t%d볼\t%d아웃\n\n", s, b, o);
	return 0;
}

static int check_input(char* my_ball) { // 정상이면 1 리턴

	if (strlen(my_ball) != SIZE) { // 자릿수 검사
		printf("4자리가 아닌 수가 입력되었습니다. 다시 입력해주십시오.\n\n"); 
		return 0;
	}

	for (int k = 0; k < SIZE; k++) {
		if (my_ball[k] < '0' || my_ball[k] > '9') { // 숫자여부 검사
			printf("숫자가 아닌 값이 입력되었습니다. 다시 입력해주십시오.\n\n");
			return 0;
		}
	}

	for (int l = 0; l < SIZE - 1; l++) { // 중복여부 검사
		for (int m = l + 1; m < SIZE; m++) {
			if (my_ball[l] == my_ball[m]) {
				printf("중복된 값이 입력되었습니다. 다시 입력해주십시오.\n\n");
				return 0;
			}
		}
	}

	return 1; // 검사 통과
}

static void win() {
	printf("\n4스트라이크!\n당신의 승리입니다!\n");
}

static void lose() {
	printf("게임 종료까지 정답을 맞히지 못하였습니다.\n당신의 패배입니다...\n");
}
