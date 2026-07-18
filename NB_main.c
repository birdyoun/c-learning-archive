#include "NumberBaseball.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// * dupli 오류, correct에 정수가 저장됨


// 정답 배열 리셋부
char correct_answer[SIZE + 1]; // NULL 넣을 공간 생각해서 +!

static void dupli_cutting() { // 정답 배열의 중복 숫자 제거 함수
	int ifdup = 0;

	for (int i = 0; i < SIZE - 1; i++) { // 숫자 하나당 배열 전체 반복 루프로 꼼꼼하게 처리, 한 숫자 앞의 수와 비교 반복
		for (int j = i + 1; j < SIZE; j++) {
			if (correct_answer[i] == correct_answer[j]) { // 중복된 경우
				if (i == j) continue; // 같은 위치 생략
				correct_answer[j] = rand() % 10 + '0';
			}
		}
	} // 이 방식은 나중갈 수록 비교대상이 감소하고, 결국 숫자 하나에 대한 전체 비교가 완전히는 안되지 않나? 단순 반복 2중이 확실하지 않은가? ****
}

static void setting() { // 정답 배열 초기화
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		correct_answer[i] = rand() % 10 + 48; // 1의 자리만 나오도록 조작 // ASCII 48~57이 0~9에 해당. 아스키를 이용한 형변환 시도
		// correct_answer[i] = (char)(rand() % 10); // 이러면 안되는 이유? 다른 int등에 저장시에는 강제 형변환이 되는데 왜 char은 안될까. 아스키 문제같은데 더 알아볼 필요 있음 ****
	}
	correct_answer[SIZE] = '\0';

	dupli_cutting();
}




// 메인
int main(void) {

	char ball[SIZE + 1];
	setting();

	printf("텍스트로 즐기는 숫자 야구 게임입니다.\n\n----------------------------------규칙----------------------------------\n");
	printf("게임은 총 9턴 동안 진행되며, 플레이어는 매 턴마다 숫자를 4개 입력합니다.\n");
	printf("입력된 숫자가 정답 4자리수와 일치하면 플레이어의 승리,\n9턴이 종료될 때까지 답을 맞추지 못하면 플레이어의 패배입니다.\n");
	printf("위치와 값이 일치하면 스트라이크, 위치는 다르지만 값이 일치하면 볼,\n위치와 값 모두 어떤 것과도 일치하지 않으면 아웃입니다.\n");
	printf("\n-----------------------------------------------------------------------\n\n");
	printf("게임을 시작합니다...\n\n");

	Number_Baseball(ball);
	return 0;
}