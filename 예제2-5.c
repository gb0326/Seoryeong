#include <stdio.h>

void main(void) {

	// 정수형 변수와 배열 선언
	int i, sale[4] = { 157, 209, 251, 312 };

	// 배열 원소 출력
	for (i = 0; i < 4; i++) {
		printf("\n address : %u sale[%d]= %d", &sale[i], i, sale[i]);
	}

	getchar();
}
