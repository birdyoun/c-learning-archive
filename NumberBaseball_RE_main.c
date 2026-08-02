#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "NumberBaseball_RE.h"
#define SIZE 4

static void rule();
static void setting(char ball[SIZE]);
static void check_duplication(char ball[SIZE]);

int main(void) { // 룰 띄우고, 정답 초기화, 메인 게임 실행

	char ball[SIZE]; // int보다 한자리씩 비교하기 더 좋을 것 같아서 char로

	rule();
	setting(ball);
	play_baseball(ball);

	return 0;
}

static void rule() {
	printf("텍스트로 즐기는 숫자 야구 게임입니다.\n\n----------------------------------규칙----------------------------------\n");
	printf("게임은 총 9턴 동안 진행되며, 플레이어는 매 턴마다 숫자를 4개 입력합니다.\n");
	printf("입력된 숫자가 정답 4자리수와 일치하면 플레이어의 승리,\n9턴이 종료될 때까지 답을 맞추지 못하면 플레이어의 패배입니다.\n");
	printf("위치와 값이 일치하면 스트라이크, 위치는 다르지만 값이 일치하면 볼,\n위치와 값 모두 어떤 것과도 일치하지 않으면 아웃입니다.\n");
	printf("\n-----------------------------------------------------------------------\n\n");
	printf("게임을 시작합니다...\n\n");
}

static void setting(char ball[SIZE]) { // 함수에서 배열을 직접 조작하여 static이어도 상관없음 리턴 필요도 없음
	srand(time(NULL)); // 이미 있는 내부 전역 상태 변화 함수라 특이하게 지역에 존재해도 영구히 기능함****
	for (int i = 0; i < SIZE; i++) {
		ball[i] = (rand() % 10) + '0'; // 일반 정수 상태면 문자 배열에 넣을때 아스키때매 변환되니까 유지를 위해 + '0'
	}
	check_duplication(ball);
}

static void check_duplication(char ball[SIZE]) {
	int catched = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (ball[i] == ball[j]) {
				ball[i] = (rand() % 10) + '0';
				catched++; // for문에서 반복이 진행될수록 변화된 앞의 값을 수정하지 못하여 catch 긴급 투입
			}
		}
	}
	if (catched != 0) {
		check_duplication(ball);
	}
}