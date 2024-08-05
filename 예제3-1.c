//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1. ����ü ��� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// 2. head ��带 ����ü�� ����
typedef struct {
	listNode* head;
} linkedList_h;

// 3. ���� ���� ����Ʈ�� �����ϴ�  ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return L;
}

// 4. ���� ����Ʈ�� ������� ����ϴ� ����
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
// 5. ������ ���� �����ϴ� ���� 
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {	// ���� ����Ʈ�� ������ ���
		L->head = newNode;   	// �� ��带 ���� ���� ����
		return;
	}
	// ���� ����Ʈ�� ������ �ƴ� ��� 
	temp = L->head;
	while (temp->link != NULL) temp = temp->link; // ���� ���
	temp->link = newNode;		// �� ��带 ���� 
}

// 6. ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}
// 7. �����Լ�
void main(void) {
	linkedList_h* L;

	printf("(1) ���� ����Ʈ �����ϱ�! \n");
	L = createLinkedList_h();
	printList(L);

	printf("\n(2) ����Ʈ �������� [��] ��� �����ϱ�! \n");
	  insertLastNode(L, "��");   printList(L);
	printf("\n(3) ����Ʈ �������� [��] ��� �����ϱ�! \n");
	  insertLastNode(L, "��");   printList(L);
    printf("\n(4) ����Ʈ �������� [��] ��� �����ϱ�! \n");
	  insertLastNode(L, "��");   printList(L);

	printf("\n(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
	  freeLinkedList_h(L);
	  printList(L);

	getchar();
}

