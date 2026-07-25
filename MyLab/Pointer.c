#include <stdio.h>


/* 
포인터 : 해당 타입의 실값 대신 변수/배열/함수 등의 주소값을 저장하는 변수
         int *p = p라는 이름의 포인터 변수 선언. p는 int타입으로 된 변수의 주소를 받음

p = 주소, *p = p가 지정한 주소에 있는 실값, &p = 포인터 변수의 주소


포인터와 배열 : 포인터와 배열을 각각 선언하여 포인터가 배열명(주소) 받아오는 형태 -> 거의 증감 조작을 위한 것?
포인터 배열 : 포인터로 된 배열 = 주소값을 받는 배열. 이러면 여러 문자열도 일반 배열은 2차원으로 받을 것을 1차원의 형태로 받을 수 있음
배열 첫 주소값만 받아오더라도 인덱스를 활용한 계산이 가능

함수 포인터 : 포인터가 함수의 첫주소를 받아옴


배열은 증감 연산 불가, 근데 포인터는 증감 연산이 가능하여 일반 배열에 대해 증감 조작이 필요한 경우 포인터 사용.
*/

static void normal_b(char b[][6], int size);
static void point_b(char* b[], int size);
static char* ph();
char hellotwo(int a, int b);
static int sum(int a, int b);
static int minus(int a, int b);

int main(void) {
    
    // 1. 포인터 배열에 이중 실값 적용?
    char* a[3];
    a[0] = "computer"; // 이 문자열이 배열에 들어가는게 아니라 첫주소가 들어감
    a[1] = "like";
    a[2] = "god";
    
    // *a[2] = "god";
    // 위의 형태로 쓰면 오류 발생. 왼쪽은 char, 오른쪽은 char *라서 타입이 안 맞습니다... 라는데 이게 먼 소리삼;;
    // 그니까 포인터 배열 인덱스 붙인 값에 *까지 붙이면 문자열 단일로 취급된다 이거임?
    // 아 완벽하게 이해했어 a[2] = 실값. &a[2] = 주소값, *a[2] = ???? 이해 못함 이게 머냐 대체 이딴게 공식이 있다고??

    int i = 0;
    while (i < 3) {
        printf("%s\n", a[i]);
        i++;
    }
    printf("-------------------------------\n");


    // 2. 증감 연산자 등 포인터 조작 적응하기
    // for (i = 0; i < 3; i++) {
    //   printf("%s\n", *a);
    //   a++; 증감으로 배열 조작은 불가능함. 포인터 변수애서는 사용되지만, 포인터 배열도 배열이므로 어떤 조작도 불가
    //}

    char* p; // 포인터를 증감하여 배열 조작하기
    char b[3] = { 'a', 'b', 'c' };
    p = b;
    for (i = 0; i < 3; i++) {
        printf("%c\t", *p);
        p++;
    } 
    printf("\n");

    p = b; // 주소 증감 상태 리셋
    *p = 'd';
    *(p + 2) = 'e'; // 증감 연산이 아니라 p의 주소값은 변화하지 않은 상태
    for (i = 0; i < 3; i++) {
        printf("%c\t", *p);
        p++;
    }
    printf("\n");

    // 2.1. 배열의 중간 주소를 가져올 수 있는가?
    p = &b[2]; // 배열명은 주소값이지만, 배열 인덱스가 적용된 중간값은 그 자체로 실값이라 주소로 사용하려면 앰퍼센드 필요
    printf("%c\n", *p);

    p = b + 1; // b라는 배열명 자체는 주소값이니 산술연산 가능
    printf("%c\n", *p);

    printf("-------------------------------\n");


    // 3. char* 타입을 가리키는 포인터는 char**타입이다????
    char** q; // 포인터 배열(char*)타입을 지정한 포인터
    q = a;
    for (i = 0; i < 3; i++) {
        printf("%s\n", *q);
        q++;
    }
    printf("-------------------------------\n");


    // 4. char* 타입 증감, 일반 배열 포인터없이 *조작 연습
    char* c[] = { "I'm", "so", "tired...", "play", "now!!!!" };
    char** cp = c;

    int normal[] = { 1,2,3,4,5 };
    *normal = 39;
    *(normal + 2) = 44;
    for (i = 0; i < 5; i++) {
        printf("%d\t", *(normal+i));
    }
    printf("\n");

    for (i = 0; i < 5; i++) {
        printf("%s ", *cp);
        cp++;
    }
    printf("\n-------------------------------\n");


    // 5. 씽크빅한 식 생각해보기
    // 5.1. 포인터 변수 2개로 일반 배열에 포인터 변수 내용 복사 -> 일반 배열은 증감 조작 불가 -> 포인터로 받아서 딸깍딸깍 ( origin -> copy로 복사 )
    char* origin = "hello"; // 복사할 것
    char* str; // 배열 조작용 포인터
    char copy[10]; // 복사받을 대상

    str = copy;

    while ((*str = *origin) != '\0') { // str에 오리진 실값 복사하고, 그게 문자열 끝인지 판정까지 한번에 슛
        str++;
        origin++;
        // 그냥 조건을 *str로 하고 복사를 내부에서 하는 경우 \0을 while 이후에 넣어줘야함, 또한 ++때매 \0칸 띄어쓰려고 while 밖에서 증가 필요는 없음
    }

    printf("%s\n", copy);
    printf("-------------------------------\n");
    // origin이 리터럴이기 때문에 포인터로 ++하지 말고 const char*로 받아서 따로 처리하는게 더 좋음


    // 6. 2차원 배열과 포인터 배열 차이 적응, 배열과 포인터 배열 구분하여 생각 의식하기
    char yas[][6] = { // 일반 배열. \0 생각해서 +1열 필요. yas[][5]면 배열 밖까지 읽게됨
        {"abcde"},
        {"fghij"}
    };

    char* yes[2] = { "lmnop", "qrstu" }; // 포인터 배열

    normal_b(yas, 2); // 2차원 배열 첫 행 주소 [0][0]
    point_b(yes, 2);

    printf("-------------------------------\n");


    // 7. []로 조작하기 + 문자열 리터럴 배열로 받아서 조작하기
    int onetwo = 12345;
    char hello[6] = "12345";
    char* charret = hello; // 배열이니까 앰퍼센드 미사용
    int* inpoint = &onetwo; // 변수니까 앰퍼센드 사용

    charret[1] = '1'; // p[i]는 컴파일러가 내부적으로 *(p + i)로 변환 = 배열에 사용하면 항상 *없이 실값 직접 조작됨
    printf("%s\n", charret); // %s는 주소를 받음
    charret = "67890";
    printf("%s\n", charret);
    printf("%d\n", *inpoint);

    printf("-------------------------------\n");



    // 8. 함수 포인터 char(*ph)와 포인터 타입 함수 char*hp 구별하여 사용해보기
    char (*hp)(int, int);
    hp = hellotwo; // 함수명도 배열명처럼 주소값
    printf("%s", ph()); // 포인터 타입 함수로 주소값을 받아서 %s에 넣기
    printf("%c\n", hp(1, 2)); 

    printf("-------------------------------\n");


    // 9. 함수 포인터 배열 써보기
    int (*hpb[2])(int, int);

    // hpb[0] = sum(1, 2); 이러면 함수 주소가 아닌 함수 계산 후 리턴 값이 들어가 int 실값이 들어가게됨 = 실패
    hpb[0] = sum;
    hpb[1] = minus;

    printf("%d, %d\n", hpb[0](1,2), hpb[1](3, 2));

    for (int j = 0; j < 2; j++) {
        printf("%d\n", hpb[j](1, 2));
    }

    printf("-------------------------------\n");


}

static int sum(int a, int b) {
    return a + b;
}

static int minus(int a, int b) {
    return a - b;
}

static char* ph() { // 포인터 타입 함수 ( != 함수 포인터 )
    return "is the point type hamsu";
}

char hellotwo(int a, int b) { // 이거 함수명이랑 위에 배열명 같아서 오류났었음 ㅡㅡ 이름 좀 적당히 지어야겠다
    printf("\n받은거 : %d, %d, ", a, b);
    return 'p'; // 문자열을 반환하려면 char*타입 변수여야 함
}

static void normal_b(char b[][6], int size) { // = char (*b)[6] ????
    for (int i = 0; i < size; i++) {
        printf("%s\n", b[i]);
    }
}

static void point_b(char* b[], int size) { // = char** b ????
    for (int i = 0; i < size; i++) {
        printf("%s\n", *b);
        b++;
    }
}
