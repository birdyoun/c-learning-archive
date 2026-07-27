#include <stdio.h>

/* 1-1
int main(void) {
	char* p = "computer";
	int i = 0;
	while (*p != '\0') {
		i++; 
		p++;
	}
	printf("%d", i);
	return 0;
}
// 결과 8
*/

/* 1-2
int main(void) {
	char x[3], * p;
	x[1] = 'A';
	p = &x[1];
	*(p - 1) = 'B';
	*(p + 1) = 'C';
	printf("%c %c %c\n", *(p - 1), *p, *(p + 1));
	return 0;
}
// 결과 B A C
*/

/* 2
void main() {
	char x[] = "JAVA programing";
	char* p;
	p = x; // 배열 리터럴이라 수정 가능

	while (*p) {
		if (*p >= 'A' && *p <= 'Z') { // 대문자 A~Z면
			printf("%c", *p - 'A' + 'a'); // 대문자의 소문자화
		}
		else {
			printf("%c", *p);
		}
		p++;
	}
	printf("\n");
}
// 대문자 아스키 < 소문자 아스키
// 둘 더한 값을 대문자 아스키에 -하면 대문자끼리 만나 소멸하고 소문자만큼의 증가가 이뤄져 소문자화가 됨
// 결과 java programing\n
*/

/*
// 3. 8개의 자료 7, 6, 77, -16, 44, 46, 6, 55를 포인터를 사용하여 버블 정렬하는 프로그램을 작성하시오. 작 -> 큰 
int main(void) {
	int a[] = { 7, 6, 77, -16, 44, 46, 6, 55 };
	int* p = a;
	int temp = 0;

	for (int i = 0; i < 8 - 1; i++) {
		for (int j = i + 1; j < 8; j++) {
			if (p[i] > p[j]) { // *없어도 실값 계산 됨 *(p+i) 이렇게 해석되기 때문 얘만 특별히
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

	for (int b = 0; b < 8; b++) { // 포인터 증감으로 출력
		printf("%d ", *p++); // 연산자 우선순위상 *처리 후 *이 아닌 주소에 ++ 계산
	}
	printf("\n");

	for (int c = 0; c < 8; c++) { // 배열 조작으로 출력
		printf("%d ", a[c]);
	}

	return 0;
}
*/

/*
// 4. 포인터 배열을 사용하여 5개의 임의의 단어를 키보드로부터 입력받아 가나다순으로 정렬하는 프로그램을 작성하시오. -> strcmp
#include <string.h>

int main(void) {
	char words[5][20]; // scanf를 위해 일반 배열을 포인터로 받는 형태로 구현
	char* p[5];
	char temp[20];
	int i = 0, j = 0;

	for (i = 0; i < 5; i++) {
		p[i] = words[i];
		scanf_s("%s", p[i], 19); // scanf로 깡으로 포인터 배열에 넣는건 불가능함. 포인터 변수는 메모리 공간을 만들지 않기 때문 !!!! 반드시 연동 필요
	}

	for (i = 0; i < 5 - 1; i++) {
		for (j = i + 1; j < 5; j++) {
			if (strcmp(p[i], p[j]) > 0) { // 양수면 앞이 더 큼
				strcpy_s(temp, 20, p[i]); // 뒤를 앞으로 복사
				strcpy_s(p[i], 20, p[j]);
				strcpy_s(p[j], 20, temp);
			}
		}
	}

	for (i = 0; i < 5; i++) { // 포인터 증감으로 출력
		//printf("%s ", p++); 
	}
	printf("\n");

	for (i = 0; i < 5; i++) { // 배열 조작으로 출력
		printf("%s ", p[i]); // char* 배열만 특수하게 주소값이 요소라 &없이도 배열 인덱스만으로 주소로 기능함
	}

	return 0;
}
*/

/*
// 5. 키보드로 입력된 이름을 5명의 이름과 비교하여 등록된 이름이 맞다면 출입 허가, 아니면 출입 불허 메세지를 출력하는 프로그램을 작성하시오.
// char* list[5] = { "Chongju", "Youngkue", "Sungduk", "Kuesik, "Changsup" };

#include <string.h>

int main(void) {
	char* list[5] = { "Chongju", "Youngkue", "Sungduk", "Kuesik", "Changsup" };
	char input[20];
	int counter = 0;

	scanf_s("%s", input, 19);

	for (int i = 0; i < 5; i++) {
		if (strcmp(input, list[i]) == 0) {
			counter++;
			break;
		}
	}

	if (counter == 0) {
		printf("출입 불허\n");
	}
	else {
		printf("출입 허가\n");
	}

	return 0;
}
*/

/*
// 6. 함수의 형식 인자로 다음과 같은 swap()을 구현하시오. (인자 두 정수를 바꾸는 역할)
void swap(int *x, int *y);

int main(void) {
	int a = 1, b = 2;
	printf("%d %d\n", a, b);

	swap(&a, &b);
	printf("%d %d\n", a, b);

	return 0;
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
*/

/*
// 7. 다음 이차원 배열을 초기화하여 각각 원소를 다음과 같이 수정하는 함수를 구현하시오.
// 5, 8, 9, 3
// 20, 5, 23, 7
// 30, 42, 4, 6
// A[i][j] = A[i][j] * 10 + 5;
// 일반 배열 조작이면 너무 쉬우니까 포인터를 쓰는게 맞는듯함 -> 근데 어떻게? A 배열을 포인터로 받아?
// 근데 int는 \0같은 종료 공식이 없어서 포인터로 받는다고 뭐 반복 횟수가 줄고 그렇지는 않을거 같은데 의미가 있나? 일단 해봐


int main(void) {
	int A[3][4] = {
		{ 5, 8, 9, 3 },
		{ 20, 5, 23, 7 },
		{ 30, 42, 4, 6 }
	};
	int* ap[3];
	int i = 0, j = 0;

	for (i = 0; i < 3; i++) {
		ap[i] = A[i]; // &A[i]는 오류날 수 있음 2차원에서는 A[i] 자체가 이미 i행 첫번째 주소라서 & 이중이 되어버림
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			ap[i][j] = ap[i][j] * 10 + 5; // ap[i]는 주소값, *ap[i]는 그 배열 첫 실값, ap[i][j]는 실값 뒤지게 난해해보이는데 생각해보면 또 당연함 
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d\t", ap[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/

/*
// 8, 9. 다음 배열을 오름차순 정렬, 내림차순 정렬하는 프로그램을 작성하시오.
// 3, 7, 8, 12, 2, 22, 1, 5, 9, 10

void naelim(int* ap);
void olim(int* ap);

int main(void) {
	// int* A[] = {3, 7, 8, 12, 2, 22, 1, 5, 9, 10}; *A[1] = 4; // 이러면 리터럴 수정이 들어가서 경고없이 오류 발생
	int A[10] = { 3, 7, 8, 12, 2, 22, 1, 5, 9, 10 }; // 이렇게 일반 배열에 포인터 달아서 조작이 제일 안전함
	int* ap = A;

	naelim(ap);
	printf("\n");
	olim(ap);
	
	return 0;
}

void naelim(int* ap) {
	int i, j, temp;

	for (i = 0; i < 10 - 1; i++) { // 큰거 올려잇 -> 내림차
		for (j = i; j < 10; j++) {
			if (ap[i] < ap[j]) {
				temp = ap[i]; // 2차원 배열이 아니라 * 없이도 주소에 달린 실값 끌어오는 해석
				ap[i] = ap[j];
				ap[j] = temp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d\t", ap[i]);
	}
}

void olim(int* ap) {
	int i, j, temp;

	for (i = 0; i < 10 - 1; i++) { // 작은거 올려잇 -> 오름차
		for (j = i; j < 10; j++) {
			if (ap[i] > ap[j]) {
				temp = ap[i]; 
				ap[i] = ap[j];
				ap[j] = temp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d\t", ap[i]);
	}
}
*/

/*
// 10. 두 이차원 배열의 더하기 빼기를 수행하는 함수를 만들어 다음 배열의 연산 결과를 알아보시오.
// 4.2  4.3  3.8     +(-)     5.2  2.1  1.8
// 3.7  1.5  0.7              3.2  1.4  2.9

void print(double A[][3]);
void plus(double A[][3], double B[][3]);
void minus(double A[][3], double B[][3]);

int main(void) { // 1. 결과 배열 따로 저장, 2. printf로 저장없이 출력만 // 1번이 지금은 더 맞는듯 함수 분리한거 알뜰하게 써먹으려면 더 좋고

	double A[2][3] = {
		{4.2, 4.3, 3.8},
		{3.7, 1.5, 0.7}
	};

	double B[2][3] = {
		{5.2, 2.1, 1.8},
		{3.2, 1.4, 2.9}
	};

	print(A);
	plus(A, B);
	print(A);
	minus(A, B);
	print(A);

	return 0;
}

void plus(double A[][3], double B[][3]) { // 행은 인자로 주는게 좋음. 열은 타입 크기에 박혀있는데 임마는 알 도리가 없고, 행 써주면 수정이 쉬워서
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			A[i][j] += B[i][j];
		}
	}
}


void minus(double A[][3], double B[][3]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			A[i][j] -= B[i][j];
		}
	}
}

void print(double A[][3]) {

	printf("\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%0.2f\t", A[i][j]);
		}
		printf("\n");
	}
}
*/

/*
교훈

1. 포인터 타입 판단을 더욱 조심하시오 그리고 더욱 적응하시오

2. 2차원도 배열명만으로 함수 인자에 넘기는 호출이 가능. 행 알빠노? 열크기가 우선임

3. []는 항상 *(p+i)로 해석되어 실값을 꺼내오는 역할, 그 실값이 또 주소값인지가 주의할 점

4. 함수 인자에서 배열은 [][]건 *건 다 *로 바꿔서 받음

5. 1차원도 동일.  g(int* a) == g(int a[])  /  g(int (*a)[3]) == g(int a[][3])

6. 행은 인자로 따로 주는게 좋음. 열은 타입 크기에 박혀있고, 행은 써주면 수정이 용이함

7. 함수 인자에서의 int (*a)[3]은 3이 열로 취급됨. 외부에서는 행이고 <<< 이게 개쳐어이없음 ㅇㅇ 모르면 죽어야지 그 자체

*/
