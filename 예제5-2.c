#include <stdio.h>
#include <stdlib.h>

typedef char element;     // ���� ť ����(element)�� �ڷ����� char�� ����

typedef struct QNode {    // ���� ť�� ��带 ����ü�� ����
	element data;
	struct QNode* link;
} QNode;

typedef struct {		// ���� ť���� ����ϴ� ������ front�� rear�� ����ü�� ����
	QNode* front, * rear;
} LQueueType;

//LQueueType* createLinkedQueue();
//int isLQEmpty(LQueueType* LQ);
//void enLQueue(LQueueType* LQ, element item);
//element deLQueue(LQueueType* LQ);
//element peekLQ(LQueueType* LQ);
//void printLQ(LQueueType* LQ);

// ���� ���� ť�� �����ϴ� ����
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isLQEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enLQueue(LQueueType* LQ, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// ���� ���� ť�� ���� ������ ���
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {						// ���� ���� ť�� ���� ���°� �ƴ� ���
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

// ���� ť���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deLQueue(LQueueType* LQ) {
	QNode* old = LQ->front;
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

// ���� ť���� ���Ҹ� �˻��ϴ� ����
element peekLQ(LQueueType* LQ) {
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = LQ->front->data;
		return item;
	}
}

// ���� ť�� ���Ҹ� ����ϴ� ����
void printLQ(LQueueType* LQ) {
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}

int main(void) {
	LQueueType* LQ = createLinkedQueue();  // ���� ť ����
	element data;
	printf("\n ***** ���� ť ���� ***** \n");
	printf("\n ���� A>>");  enLQueue(LQ, 'A'); printLQ(LQ);
	printf("\n ���� B>>");  enLQueue(LQ, 'B'); printLQ(LQ);
	printf("\n ���� C>>");  enLQueue(LQ, 'C'); printLQ(LQ);
	data = peekLQ(LQ);    printf(" peek item : %c \n", data);
	printf("\n ����  >>");  data = deLQueue(LQ); printLQ(LQ);
	printf("\t���� ������: %c", data);
	printf("\n ����  >>");  data = deLQueue(LQ); printLQ(LQ);
	printf("\t���� ������: %c", data);
	printf("\n ����  >>");  data = deLQueue(LQ); printLQ(LQ);
	printf("\t\t���� ������: %c", data);
	printf("\n ���� D>>");  enLQueue(LQ, 'D'); printLQ(LQ);
	printf("\n ���� E>>");  enLQueue(LQ, 'E'); printLQ(LQ);
	getchar();  return 0;
}
