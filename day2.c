#include <stdio.h>

// ��� �����Լ� ����
int insertElement(int L[], int n, int x) {
	int i, k = 0, move = 0; //move�� �ڸ��̵� Ƚ�� ī����
	//������ ũ�⸦ ���Ͽ� ���� ��ġ k ã��
	for (i = 0; i < n; i++) {
		if (L[i] <= x && x <= L[i + 1]) {
			k = i + 1;
			break;
		}
	}
	if (i == n) //���� ���Ұ� ���� ū ������ ���
		k = n;
	// ������ ���Һ��� k+1���ұ��� �ڷ� �ڸ��̵�
	for (i = n; i > k; i--) {
		L[i] = L[i - 1];
		move++;
	}
	L[k] = x;//�ڸ� �̵��Ͽ� ���� �ڸ� k�� ���� ���� ����

	return move;
}

// ��� �����Լ� ����
int deleteElement(int L[], int n, int x) {
	int i, k = n, move = 0; //move�� �ڸ��̵� Ƚ�� ī����
	//������ ũ�⸦ ���Ͽ� ���� ��ġ k ã��
	for (i = 0; i < n; i++) {
		if (L[i] == x) {
			k = i;
			break;
		}
	}
	if (i == n) move = n;
	// k+1 ���� ������ ���ұ��� ������ �ڸ��̵�
	for (i = k; i < n - 1; i++) {
		L[i] = L[i + 1];
		move++;
	}

	return move;
}

// ���� �Լ�
void main() {
	int list[10] = { 10, 20, 40, 50, 60, 70 };
	int i, move, size = 6; //size�� ����Ʈ�� �ִ� ������ ����

	printf("\n���� �� ���� ����Ʈ : ");
	for (i = 0; i < size; i++)
		printf("%3d ", list[i]);
	printf("\n������ ���� : %d \n", size);
	move = insertElement(list, size, 30);

	printf("\n���� �� ���� ����Ʈ : ");
	for (i = 0; i <= size; i++)
		printf("%3d ", list[i]);
	printf("\n������ ���� : %d ", ++size);
	printf("\n�ڸ� �̵� Ƚ�� : %d \n", move);
	move = deleteElement(list, size, 30);
	if (move == size)
		printf("\n���� ����Ʈ�� ���Ұ� ��� ������ �� �����ϴ�.\n");
	else {
		printf("\n���� �� ���� ����Ʈ : ");
		for (i = 0; i < size - 1; i++) printf("%3d ", list[i]);
		printf("\n������ ���� : %d ", --size);
		printf("\n�ڸ� �̵� Ƚ�� : %d \n", move);
	}
}