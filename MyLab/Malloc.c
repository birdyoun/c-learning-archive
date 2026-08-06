// stdlib.h 인클루드 -> void* malloc(size_t size); void free(void* ptr);
// *변수 = (*변수의 타입) malloc(*변수의 타입 크기 x 필요 크기);
// int* p = (int*)malloc(sizeof(int) * 4); 이런 형태

// 그니까 malloc으로 지정한 크기만큼의 메모리를 가진 공간 <- 이거 만들고, 그 후에 그거의 주소를 리턴받음.
// = malloc을 통해 얻는 값은 주소값. *로 받아야 함. 그리고 그냥 주소값이라 포인터 조작하면 됨

// gets() 이거 사용 가능함? 삭제된거 아님?

#include <stdio.h>
int main(void) {
	int a = 0;
	char c[30];
	char* cp;

	/*
	printf("정수 입력 : ");
	fgets(&a, 20, stdin);
	printf("\n정수 출력 : ");
	puts(a);
	*/

	printf("\n문자열 입력 : ");
	fgets(c, 30, stdin);
	printf("\n문자열 출력1 : ");
	puts(c);

	cp = c;
	printf("\n문자열 출력2 : ");
	puts(cp);

	return 0;
}

// int는 fgets 적용 시점에 터짐. 디버거 실행하고 cmd 창에서 터지는거고 오류 없음
// 포인터 실값 형태로 puts시 정지됨. 이론상 될거 같은데 안되네... %s 이게 아니라 그런가? 머지 -> 주소를 받는거라서 그랬네 실값받는게 아님