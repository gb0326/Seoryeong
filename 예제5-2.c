#include <stdio.h>
#include <stdlib.h>

typedef char element;     // 연결 큐 원소(element)의 자료형을 char로 정의

typedef struct QNode {    // 연결 큐의 노드를 구조체로 정의
	element data;
	struct QNode* link;
} QNode;

typedef struct {		// 연결 큐에서 사용하는 포인터 front와 rear를 구조체로 정의
	QNode* front, * rear;
} LQueueType;

//LQueueType* createLinkedQueue();
//int isLQEmpty(LQueueType* LQ);
//void enLQueue(LQueueType* LQ, element item);
//element deLQueue(LQueueType* LQ);
//element peekLQ(LQueueType* LQ);
//void printLQ(LQueueType* LQ);

// 공백 연결 큐를 생성하는 연산
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isLQEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enLQueue(LQueueType* LQ, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// 현재 연결 큐가 공백 상태인 경우
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {						// 현재 연결 큐가 공백 상태가 아닌 경우
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
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

// 연결 큐에서 원소를 검색하는 연산
element peekLQ(LQueueType* LQ) {
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = LQ->front->data;
		return item;
	}
}

// 연결 큐의 원소를 출력하는 연산
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
	LQueueType* LQ = createLinkedQueue();  // 연결 큐 생성
	element data;
	printf("\n ***** 연결 큐 연산 ***** \n");
	printf("\n 삽입 A>>");  enLQueue(LQ, 'A'); printLQ(LQ);
	printf("\n 삽입 B>>");  enLQueue(LQ, 'B'); printLQ(LQ);
	printf("\n 삽입 C>>");  enLQueue(LQ, 'C'); printLQ(LQ);
	data = peekLQ(LQ);    printf(" peek item : %c \n", data);
	printf("\n 삭제  >>");  data = deLQueue(LQ); printLQ(LQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제  >>");  data = deLQueue(LQ); printLQ(LQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제  >>");  data = deLQueue(LQ); printLQ(LQ);
	printf("\t\t삭제 데이터: %c", data);
	printf("\n 삽입 D>>");  enLQueue(LQ, 'D'); printLQ(LQ);
	printf("\n 삽입 E>>");  enLQueue(LQ, 'E'); printLQ(LQ);
	getchar();  return 0;
}
