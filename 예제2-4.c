#include <stdio.h>
#include <string.h>

struct employee {	// 구조체선언
	char name[10];
	int year;
	int pay;
};

void main() {
	int i;
	struct employee Lee[4] = {    //구조체 배열
	{ "이진호", 2022, 5200 },
	{ "이한영", 2023, 4300 },
	{ "이상원", 2023, 4500 },
	{ "이상범", 2024, 3900 }
	};

	for (i = 0; i < 4; i++) {	// 구조체 출력
		printf("\n 이름 : %s", Lee[i].name);
		printf("\n 입사 : %d", Lee[i].year);
		printf("\n 연봉 : %d \n", Lee[i].pay);
	}
	getchar();
}
