#include <stdio.h>
#include "TicTacToe.h"

static void setting(void);
static void rule(void);

int main(void) {

	rule();
	tictactoe();

	return 0;
}

static void rule() {
	printf("----------------------------------------\n");
	printf("2인용 틱택토 게임입니다.\n");
	printf("2명이 서로 번갈아가며 3*3 넓이의 판에 돌을 둡니다.\n");
	printf("돌은 해당 위치와 동일한 숫자를 입력하여 두며,\n");
	printf("둘 중 한명의 돌이 대각선, 가로, 세로 중 어떤 방향이든 3개 정렬된 순간 그 플레이어의 승리로 게임이 종료됩니다.\n");
	printf("X가 선공, O가 후공이며, 9턴동안 승부가 나지 않으면 무승부로 처리되어 게임이 다시 시작됩니다.\n");
	printf("승리한 사람은 명예의 전당에 자신의 이름을 적을 수 있으며, 이름과 함께 게임 종료시까지의 턴 수가 기록됩니다.\n");
	printf("명예의 전당은 m키를 눌러서 열 수 있습니다.\n");
	printf("----------------------------------------\n");
	printf("\n");
}
