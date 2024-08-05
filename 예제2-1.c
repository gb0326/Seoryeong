#include <stdio.h>

void main() {
	char c;		// 문자형 변수
	int i;		// 정수형 변수
	short s;		//  반밀도 정수형 변수
	float f;		// 부동소수점형 변수
	long l;		// 배밀도 정수형 변수

	printf("\n char c 크기 = %d 바이트", sizeof(c));
	printf("\n int i 크기 = %d 바이트", sizeof(i));
	printf("\n short s 크기 = %d 바이트", sizeof(s));
	printf("\n float f 크기 = %d 바이트", sizeof(f));
	printf("\n long l 크기 = %d 바이트", sizeof(l));

	printf("\n");  getchar();  // 실행 창이 닫히지 않게 하기 위해 편의상 추가한 입력 대기 명령
}
