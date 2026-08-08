#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe.h"

// 더 필요한거 : ox 5회이후 리턴, 명전

// 1. 메인 게임 전체 흐름을 총괄하는 함수
// 2. 보드를 육안으로 볼 수 있게 출력해주는 보드 함수
// 3. 승리 여부를 매 입력마다 판단하는 판단 함수
// 4. 무승부 판정 함수
// 5. 명예의 전당 입력 함수
// main.c에서는 함수 1 만을 main 함수에 작성하여 사용합니다.

int tictactoe(void); // 1
static void print_board(int turn, char temp); // 2 
static int input_check(int turn); // 3 
static int ox_check(); // 3
static void draw(); // 4*
static void win(int turn); // 5
static int is_valid_input(char player_input); // 3번 내에서 사용자 입력 검사로 사용
static void setting(); // * 시작 직후 판 보여주는 용도

static char input[3][3] = { // 계속 이 배열에 쌓아가는 방식으로 할거라 static으로 설정
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
};

int tictactoe(void) { // input_check로 입력받고, 검사하고, 그 입력 순간에 o 또는 x가 정렬에 성공시 win 함수를 호출
	int i = 0;

	setting();
	for (i = 0; i < 9; i++) {
		if (input_check(i + 1)) { // 턴 써먹을때 0부터 오르면 일반적인 수식 계산과 좀 달라져서 그냥 +1함
			win(i + 1);
			return 0;
		}
	}

	draw();
	return 0;
}

static void print_board(int turn, char temp) { // check에서 배열을 포인터로 받아서 출력 + 입력 확인도 필요함 0같은거 넣으면 터진다
	printf("\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (((temp - 1) / 3) == i && ((temp - 1) % 3) == j) { // 사용자가 입력한 ij 위치와 for가 지정하고 있는 곳이 동일한 경우
				if ((turn % 2) == 0) { // 턴 수에 따른 o, x 판별
					input[i][j] = 'o';
				}
				else {
					input[i][j] = 'x';
				}
			}
			printf("%c ", input[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

static int input_check(int turn) {
	char temp = { 0 };

	do { // 정상 입력까지 무한 반복
		scanf_s("%c", &temp, 1);
	} while (!is_valid_input(temp));

	print_board(turn, temp);

	if (turn >= 5) { // 서로 번갈아 돌을 두면 5회의 입력부터 정렬될 가능성이 생기므로 이때부터 검사
		if (ox_check()) { // 1이 리턴되면 메인에서 for 종료
			return 1;
		}
	}
	return 0;
}

static int ox_check() { // 대각, 가로, 세로 for로 구분하여 ox 확인 (x카운터와 o카운터를 사용하여 각각 축적 후 검사)
	int i = 0, j = 0, count[2] = { 0, 0 }; // count[0]은 o, 1은 x의 돌 카운트

	// 대각
	for (i = 0; i < 3; i++) { // 정대각
		if (input[i][i] == 'o') {
			count[0]++;
		}
		else if (input[i][i] == 'x') {
			count[1]++;
		}
	}
	if (count[0] == 3 || count[1] == 3) { // 검사 후 리턴
		return 1;
	}
	count[0] = 0, count[1] = 0;
	

	for (i = 0; i < 3; i++) { // 역대각 *
		if (input[i][2-i] == 'o') {
			count[0]++;
		}
		else if (input[i][2 - i] == 'x') {
			count[1]++;
		}
	}
	
	if (count[0] == 3 || count[1] == 3) { // 검사 후 리턴
		return 1;
	}
	count[0] = 0, count[1] = 0;
	

	// 가로
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (input[i][j] == 'o') {
				count[0]++;
			}
			else if (input[i][j] == 'x') {
				count[1]++;
			}
		}
		if (count[0] == 3 || count[1] == 3) { // 검사 후 리턴
			return 1;
		}
		count[0] = 0, count[1] = 0;
	}
	

	// 세로
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (input[j][i] == 'o') {
				count[0]++;
			}
			else if (input[j][i] == 'x') {
				count[1]++;
			}
		}
		if (count[0] == 3 || count[1] == 3) { // 검사 후 리턴
			return 1;
		}
		count[0] = 0, count[1] = 0;
	}

	return 0;
}

static int is_valid_input(char player_input) { // 문제 없으면 1 반환
	if (player_input< '1' || player_input > '9') { // 숫자 범위 확인
		printf("\n잘못된 입력입니다. 다시 입력해주십시오.\n\n");
		return 0;
	}
	if (input[(player_input - 1) / 3][(player_input - 1) % 3] == 'o' || input[(player_input - 1) / 3][(player_input - 1) % 3] == 'x') { // 자리 확인
		printf("\n잘못된 입력입니다. 다시 입력해주십시오.\n\n");
		return 0;
	}
	return 1;
}

static void draw() { // for 자연 종료시 로드하여 재시작하는 용
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			input[i][j] = ((i * 3) + j) + '1'; // count 없이 식으로 짜보기 각 행의 0번 항목은 0, 3, 6 전부 3의 배수 거기에 더하기만 하면 됨
		}
	}
	printf("\n승부가 나지 않았습니다. 게임을 다시 시작합니다.\n\n");
	tictactoe();
}

static void setting() {
	for (int i = 0; i < 9; i += 3) {
		printf("%d %d %d\n", i + 1, i + 2, i + 3);
	}
	printf("\n");
}

static void win(int turn) { // 승리 결정 시 ttt 함수 내에서 호출되도록

	if ((turn % 2) == 0) { // 홀 = x승, 짝 = o승
		printf("o의 승리입니다!\n게임을 종료합니다...\n");
	}
	else {
		printf("x의 승리입니다!\n게임을 종료합니다...\n");
	}
}