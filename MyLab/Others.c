#include <stdio.h>

/*
int main(void) {
	// 1. 조건검사와 반복횟수는 완전히 별개다? - 조건 검사와 반복횟수 개별 출력해보기
	int i = 0, p = 1;

	printf("0으로 정지 : ");

	for (i = 0; i < 5; i++) {
		scanf_s("%d", &p);
		if (p != 0) printf("반복중...\t");
		else {
			printf("\n반복 정지. 반복 횟수 : %d\n", i);
			break;
		}
	}
	printf("조건 검사 횟수 : %d", i);
	// 조건식 이후에 증감이 적용되어 수식으로 조건 검사 횟수를 가져오는건 불가능한듯???? +1로 짜치게 해야되는건가 이거
}
*/

int main(void) {
	// 2. 파일 입출력 기본 해보기
	FILE* fp;
	char what[50] = { 0 };
	char come[50] = { 0 };

	// fp = fopen("testf.txt", "a+");
	fopen_s(&fp, "testf.txt", "w");
	if (fp == NULL) {
		printf("파일을 찾을 수 없습니다.");
		return 1;
	}

	printf("무엇을 쓸 지 적으시오 : ");
	scanf_s("%s", what, 50);

	fprintf(fp, "%s", what);
	fclose(fp); // 다시 닫고 열지 않으면 fprintf 끝난 시점에 포인터가 끝까지 이동된 상태라 fscanf가 생각대로 작동하지 않음****

	fopen_s(&fp, "testf.txt", "r");
	if (fp == NULL) {
		printf("파일을 찾을 수 없습니다.");
		return 1;
	}
	fscanf_s(fp, "%s", come, 50);

	printf("\n%s", what);
	printf("\n%s", come);

	fclose(fp);
	return 0;

} // txt있고 작성도 되었는데 왜 fscanf 안먹지???? printf에서 come이 \n%s에서 \n만 작동함 오류가 뜨는것도 아니야 -> 해결

// a 모드가 좀 많이 어렵네 wr로 하니까 생각대로 되는데 a는 머 이상한 일이 일어나 얘가 항상 파일 끝에서 포인터 시작이라 그렇다네요