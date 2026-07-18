#include "NumberBaseball.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




extern char correct_answer[SIZE + 1];

// 숫자 입력부
int Number_Baseball(char* input_ball) {
	static int round = 0;
	round++; // 실행마다 회차 1증가

	// 입력
	printf("\n%d회차입니다. 4자리 숫자를 입력해주십시오 : ", round);
	scanf_s("%s", input_ball, SIZE + 1); 
	while (getchar() != '\n'); // 오류 방지 ****
	
	if (check_ball(input_ball) == 1) { // 승리한 경우
		printf("\n4 스트라이크! 정답을 맞췄습니다!\n플레이어의 승리입니다!\n게임을 종료합니다...\n");
	}
	else if (round == 9){ // 패배한 경우
		printf("\n모든 회차가 종료되었습니다.\n정답은 %s입니다.\n플레이어의 패배입니다...\n\n게임을 종료합니다...", correct_answer);
	}
	else {
		Number_Baseball(input_ball); // 정답이 아닌 경우 재귀 반복
	}
	return 0;
} // + for로 하는게 의미적으로 옳다고 함. for쓰려면 round를 i 대용으로 조건구문에 쓰면 될 듯 ****




// 숫자 검증부. 검증 후 입력부 재시작 또는 승리에 따른 프로그램 조기 종료
int check_ball(char* input_ball) {
	int s = 0, b = 0, o = 0, win_counter = 0, out_counter = 0;
	// s, b, o 유무 분석
	for (int i = 0; i < SIZE; i++) {
		if (input_ball[i] == correct_answer[i]) { // 스트라이크인 경우
			s++;
			win_counter++;
		}
		else { // 스트라이크가 아니면 볼, 아웃 구분부로 들어옴, 볼, 아웃은 위치 불일치라는 공통점을 공유하므로 위치 안보고 값만 확인
			for (int j = 0; j < SIZE; j++) {
				if (input_ball[i] == correct_answer[j]) { // 볼인 경우
					b++;
				}
				else { // 아웃인 경우
					out_counter++; // 4번 다 틀리면 아웃, 단, 모든 숫자에 대해 아웃 여부를 확인해야하므로 for 종료 전까지 카운터를 사용
				}
			}
			if (out_counter == 4) o++; // 4번 반복 스캔 종료 후 최종적으로 아웃 처리
		}
		out_counter = 0;
	}
	if (win_counter != SIZE) { // 승리하지 않은 경우 루프
		printf("%d 스트라이크, %d 볼, %d 아웃\n", s, b, o);
		return 0;
	}
	else { // 승리한 경우
		return 1;
	}

}