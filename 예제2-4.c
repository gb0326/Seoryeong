#include <stdio.h>
#include <string.h>

struct employee {	// ����ü����
	char name[10];
	int year;
	int pay;
};

void main() {
	int i;
	struct employee Lee[4] = {    //����ü �迭
	{ "����ȣ", 2022, 5200 },
	{ "���ѿ�", 2023, 4300 },
	{ "�̻��", 2023, 4500 },
	{ "�̻��", 2024, 3900 }
	};

	for (i = 0; i < 4; i++) {	// ����ü ���
		printf("\n �̸� : %s", Lee[i].name);
		printf("\n �Ի� : %d", Lee[i].year);
		printf("\n ���� : %d \n", Lee[i].pay);
	}
	getchar();
}
