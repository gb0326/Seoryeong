#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 구조체 노드 정의
typedef struct ListNode {
    char name[30];
    int studentID; // 학번을 int 형으로 변경
    struct ListNode* link;
} listNode;

// 2. head 노드를 구조체로 정의
typedef struct {
    listNode* head;
} linkedList_h;

// 3. 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL; // 공백 리스트이므로 NULL로 설정
    return L;
}

// 4. 연결 리스트를 순서대로 출력하는 연산
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

// 5. 학번 순서로 노드를 삽입하는 연산
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

// 6. 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
    }
}

// 7. 메인함수
int main(void) {
    linkedList_h* L;
    char name[30];
    int studentID;

    L = createLinkedList_h(); // 공백 단순 연결 리스트 생성

    printList(L);

    while (1) {
        printf("\n이름--> ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // 개행 문자 제거

        if (strlen(name) == 0) break; // Enter 키를 누르면 입력 종료

        printf("학번--> ");
        if (scanf("%d", &studentID) != 1) {
            // 입력 오류 처리
            printf("유효한 학번을 입력하세요.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }
        while (getchar() != '\n'); // 입력 버퍼 비우기

        insertSortedByStudentID(L, name, studentID);
        printList(L);
    }

    printf("\n프로그램을 종료합니다.\n");

    freeLinkedList_h(L); // 메모리 해제
    return 0;
}