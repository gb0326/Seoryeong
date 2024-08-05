#include <stdio.h>
#include <stdlib.h>

typedef char element;	// ��ũ ����(element)�� �ڷ����� char�� ����

typedef struct DQNode {	// ���� ���� ����Ʈ ��ũ�� ��� ������ ����ü�� ����
	element data;
	struct DQNode* llink;
	struct DQNode* rlink;
} DQNode;

typedef struct {       // ��ũ���� ����ϴ� ������ front�� rear�� ����ü�� ����
	DQNode* front, * rear;
} DQueType;

// ���� ��ũ�� �����ϴ� ����
DQueType* createDQue() {
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// ��ũ�� ���� �������� �˻��ϴ� ����
int isDeQEmpty(DQueType* DQ) {
	if (DQ->front == NULL)  return 1;
	else return 0;
}

// ��ũ�� front ������ ���Ҹ� �����ϴ� ����
void insertFront(DQueType* DQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDeQEmpty(DQ)) {   // ��ũ�� ���� ������ ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->front->llink = newNode;
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front = newNode;
	}
}

// ��ũ�� rear �ڷ� ���Ҹ� �����ϴ� ����
void insertRear(DQueType* DQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDeQEmpty(DQ)) {   // ��ũ�� ���� ������ ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
}

// ��ũ�� front ��带 �����ϰ� ��ȯ�ϴ� ����
element deleteFront(DQueType* DQ) {
	DQNode* old = DQ->front;
	element item;
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n");  return;
	}
	else {
		item = old->data;
		if (DQ->front->rlink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}

// ��ũ�� rear ��带 �����ϰ� ��ȯ�ϴ� ����
element deleteRear(DQueType* DQ) {
	DQNode* old = DQ->rear;
	element item;
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;
	}
	else {
		item = old->data;
		if (DQ->rear->llink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

// ��ũ�� front ����� ������ �ʵ带 ��ȯ�ϴ� ����
element peekFront(DQueType* DQ) {
	element item;
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;
	}
	else {
		item = DQ->front->data;
		return item;
	}
}

// ��ũ�� rear ����� ������ �ʵ带 ��ȯ�ϴ� ����
element peekRear(DQueType* DQ) {
	element item;
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;
	}
	else {
		item = DQ->rear->data;
		return item;
	}
}

// ��ũ�� front ������ rear ������ ����ϴ� ����
void printDQ(DQueType* DQ) {
	DQNode* temp = DQ->front;
	printf("DeQue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf(" ] ");
}

int main(void)
{
	DQueType* DQ1 = createDQue();  // ��ũ ����
	element data;
	printf("\n ***** ��ũ ���� ***** \n");
	printf("\n front ���� A>> ");  insertFront(DQ1, 'A');  printDQ(DQ1);
	printf("\n front ���� B>> ");  insertFront(DQ1, 'B');  printDQ(DQ1);
	printf("\n rear  ���� C>> ");  insertRear(DQ1, 'C');  printDQ(DQ1);
	printf("\n front ����  >> ");  data = deleteFront(DQ1);  printDQ(DQ1);
	printf("\t���� ������: %c", data);
	printf("\n rear  ����  >> ");  data = deleteRear(DQ1);   printDQ(DQ1);
	printf("\t\t���� ������: %c", data);
	printf("\n rear  ���� D>> ");  insertRear(DQ1, 'D');  printDQ(DQ1);
	printf("\n front ���� E>> ");  insertFront(DQ1, 'E');  printDQ(DQ1);
	printf("\n front ���� F>> ");  insertFront(DQ1, 'F');  printDQ(DQ1);

	data = peekFront(DQ1);  printf("\n peek Front item : %c \n", data);
	data = peekRear(DQ1);  printf(" peek Rear item : %c \n", data);

	getchar();  return 0;
}
