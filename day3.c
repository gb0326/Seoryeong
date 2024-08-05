#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ����ü ��� ����
typedef struct ListNode {
    char name[30];
    int studentID; // �й��� int ������ ����
    struct ListNode* link;
} listNode;

// 2. head ��带 ����ü�� ����
typedef struct {
    listNode* head;
} linkedList_h;

// 3. ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL; // ���� ����Ʈ�̹Ƿ� NULL�� ����
    return L;
}

// 4. ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
    listNode* p;

    p = L->head;
    while (p != NULL) {
        printf("[%s, %d]", p->name, p->studentID);
        p = p->link;
        if (p != NULL) printf(" ");
    }
    printf("\n");
}

// 5. �й� ������ ��带 �����ϴ� ����
void insertSortedByStudentID(linkedList_h* L, char* name, int studentID) {
    listNode* newNode;
    listNode* current;
    listNode* previous = NULL;

    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->name, name);
    newNode->studentID = studentID;
    newNode->link = NULL;

    if (L->head == NULL || L->head->studentID > studentID) {
        newNode->link = L->head;
        L->head = newNode;
    }
    else {
        current = L->head;
        while (current != NULL && current->studentID <= studentID) {
            previous = current;
            current = current->link;
        }
        newNode->link = current;
        previous->link = newNode;
    }
}

// 6. ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
    }
}

// 7. �����Լ�
int main(void) {
    linkedList_h* L;
    char name[30];
    int studentID;

    L = createLinkedList_h(); // ���� �ܼ� ���� ����Ʈ ����

    printList(L);

    while (1) {
        printf("\n�̸�--> ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // ���� ���� ����

        if (strlen(name) == 0) break; // Enter Ű�� ������ �Է� ����

        printf("�й�--> ");
        if (scanf("%d", &studentID) != 1) {
            // �Է� ���� ó��
            printf("��ȿ�� �й��� �Է��ϼ���.\n");
            while (getchar() != '\n'); // �Է� ���� ����
            continue;
        }
        while (getchar() != '\n'); // �Է� ���� ����

        insertSortedByStudentID(L, name, studentID);
        printList(L);
    }

    printf("\n���α׷��� �����մϴ�.\n");

    freeLinkedList_h(L); // �޸� ����
    return 0;
}