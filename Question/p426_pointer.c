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
				strcpy(temp, p[i]); // 뒤를 앞으로 복사
				strcpy(p[i], p[j]);
				strcpy(p[j], temp);
			}
		}
	}

	for (i = 0; i < 5; i++) { // 포인터 증감으로 출력
		//printf("%s ", p++); 
	}
	printf("\n");

	for (i = 0; i < 5; i++) { // 배열 조작으로 출력
		printf("%s ", &p[i]); // 내 지식 : 배열명 = 주소, 배열[n] = 실값 ( = *p(n+m) ), %s 형식 지정자 <- 주소값 인자를 받음
	} // 내 생각엔 다 맞는데 이거 왜 안 됨 ㅈㅈ

	return 0;
} // 111행 'printf' : 서식 문자열 '%s'에 'char *' 형식의 인수가 필요하지만 variadic 인수 1의 형식이 'char **'입니다. 아니 이거 무슨뜻????


// 5. 키보드로 입력된 이름을 5명의 이름과 비교하여 등록된 이름이 맞다면 출입 허가, 아니면 출입 불허 메세지를 출력하는 프로그램을 작성하시오.
// char* list[5] = { "Chongju", "Youngkue", "Sungduk", "Kuesik, "Changsup" };
