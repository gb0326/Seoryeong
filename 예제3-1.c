//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1. 구조체 노드 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// 2. head 노드를 구조체로 정의
typedef struct {
	listNode* head;
} linkedList_h;

// 3. 공백 연결 리스트를 생성하는  연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;// 공백 리스트이므로 NULL로 설정
	return L;
}

// 4. 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}
// 5. 마지막 노드로 삽입하는 연산 
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {	// 현재 리스트가 공백인 경우
		L->head = newNode;   	// 새 노드를 시작 노드로 연결
		return;
	}
	// 현재 리스트가 공백이 아닌 경우 
	temp = L->head;
	while (temp->link != NULL) temp = temp->link; // 최종 노드
	temp->link = newNode;		// 새 노드를 연결 
}

// 6. 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}
// 7. 메인함수
void main(void) {
	linkedList_h* L;

	printf("(1) 공백 리스트 생성하기! \n");
	L = createLinkedList_h();
	printList(L);

	printf("\n(2) 리스트 마지막에 [월] 노드 삽입하기! \n");
	  insertLastNode(L, "월");   printList(L);
	printf("\n(3) 리스트 마지막에 [수] 노드 삽입하기! \n");
	  insertLastNode(L, "수");   printList(L);
    printf("\n(4) 리스트 마지막에 [금] 노드 삽입하기! \n");
	  insertLastNode(L, "금");   printList(L);

	printf("\n(5) 리스트 공간을 해제하여 공백 리스트로 만들기! \n");
	  freeLinkedList_h(L);
	  printList(L);

	getchar();
}

