#include <stdio.h>

void main() {
	char c;		// ������ ����
	int i;		// ������ ����
	short s;		//  �ݹе� ������ ����
	float f;		// �ε��Ҽ����� ����
	long l;		// ��е� ������ ����

	printf("\n char c ũ�� = %d ����Ʈ", sizeof(c));
	printf("\n int i ũ�� = %d ����Ʈ", sizeof(i));
	printf("\n short s ũ�� = %d ����Ʈ", sizeof(s));
	printf("\n float f ũ�� = %d ����Ʈ", sizeof(f));
	printf("\n long l ũ�� = %d ����Ʈ", sizeof(l));

	printf("\n");  getchar();  // ���� â�� ������ �ʰ� �ϱ� ���� ���ǻ� �߰��� �Է� ��� ���
}
