#include <stdio.h>
#define STACK_SIZE 100

typedef int element;        // 스택원소자료형 int 정의 
element stack[STACK_SIZE];  // 1차원 스택 선언
int top = -1;

// 1. 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// 2. 스택이 포화 상태인지 확인하는 연산
int isStackFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

// 3. 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	if (isStackFull()) {        // 스택이 포화 상태인 경우
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;// top 증가후 원소 삽입
}
// 4. 스택의 top에서 원소를 삭제하는 연산
element pop() {
	if (isStackEmpty()) {            // 스택이 공백 상태인 경우
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];      // 현재 원소삭제후 top 감소
}

// 5. 스택의 top 원소를 검색하는 연산
element peek() {
	if (isStackEmpty()) {          // 스택이 공백 상태인 경우
		printf("\n\n Stack is Empty !\n");
		exit(1);
	}
	else return stack[top];       // 현재 top의 원소 확인
}

// 6. 스택의 원소를 출력하는 연산
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}
// 7. 메인함수
void main(void) {
	element item;
	printf("\n** 순차 스택 연산 **\n");
	printStack();
	push(1);   printStack();		// 1 삽입
	push(2);   printStack();		// 2 삽입
	push(3);   printStack();   		// 3 삽입

	item = peek();  printStack();                   // 현재 top의 원소 출력
	printf("peek => %d", item);

	item = pop();  printStack();		// 삭제
	printf("\t pop  => %d", item);

	item = pop();  printStack();		// 삭제
	printf("\t pop  => %d", item);

	item = pop();  printStack();		// 삭제
	printf("\t pop  => %d\n", item);

	getchar();
}
