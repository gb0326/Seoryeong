#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;             // 스택 원소자료형  int 
typedef struct  stackNode { // 스택노드 구조체
    element data;
    struct stackNode* link;
} stackNode;
stackNode* top;	//  top스택포인터

// 1. 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

// 2. 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    stackNode* temp =
        (stackNode*)malloc(sizeof(stackNode));

    temp->data = item;
    temp->link = top;     // 삽입노드를 top 위에 연결
    top = temp;           // top 위치를 삽입 노드로 이동
}
// 3. 스택의 top에서 원소를 삭제하는 연산
element pop() {
    element item;
    stackNode* temp = top;

    if (isStackEmpty()) {// 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {// 스택이 공백 리스트가 아닌 경우
        item = temp->data;
        top = temp->link;// top 위치를 삭제 노드 아래로 이동
        free(temp);// 삭제된 노드의 메모리 반환
        return item;// 삭제된 원소 반환
    }
}
// 4. 스택의 top 원소를 검색하는 연산
element peek() {
    if (isStackEmpty()) {          // 스택이 공백 상태인 경우
        printf("\n\n Stack is Empty !\n");
        return 0;
    }
    else return(top->data);       // 현재 top의 원소 확인
}
// 5. 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack() {
    stackNode* p = top;
    printf("\n STACK [ ");
    while (p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("] ");
}
// 6. 메인함수
int main(void) {
    element item;
    top = NULL;
    printf("\n** 연결 스택 연산 **\n");
    printStack();

    push(1);    printStack();		// 1 삽입
    push(2);    printStack();		// 2 삽입
    push(3);    printStack();		// 3 삽입

    item = peek(); printStack();    // 현재 top의 원소 출력
    printf("peek => %d", item);

    item = pop();  printStack();	// 삭제
    printf("\t pop  => %d", item);

    item = pop();  printStack();	// 삭제
    printf("\t pop  => %d", item);

    item = pop();  printStack();	// 삭제
    printf("\t pop  => %d\n", item);

    getchar();  return 0;
}
