#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;		// 스택 원소(element)의 자료형을 char로 정의 

typedef struct  stackNode {	// 스택의 노드를 구조체로 정의
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;				// 스택의 top 노드를 지정하기 위해 포인터 top 선언

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;     // 삽입 노드를 top의 위에 연결
	top = temp;           // top 위치를 삽입 노드로 이동
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {		// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		item = temp->data;
		top = temp->link;	// top 위치를 삭제 노드 아래로 이동
		free(temp);			// 삭제된 노드의 메모리 반환
		return item;		// 삭제된 원소 반환
	}
}

// 스택의 top 원소를 검색하는 연산
element peek() {
	if (isStackEmpty()) {		// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		return(top->data);  // 현재 top의 원소 반환
	}
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

// 중위식을 후위식으로 변환하는 연산
void inFix2postFix(char* exp) {

	char symbol;
	int i, length = strlen(exp);
	top = NULL;
		
	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
			// (1) 피연산자이면 출력
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			printf("%c", symbol);
			break;
			// (2) 연사자이면 push
		case '+':		case '-':		case '*':		case '/':
			push(symbol);  
			break;
		// 4) 우괄호이면 pop & 출력
		case ')':		case '}':		case ']':
			printf("%c", pop()); 
			break;
		default : 
			break;
		}
	}
	while (top != NULL) {
		printf("%c", pop());
	}
	printf("\n");
}

void main(void) {
	int result;
	char* express = "(3*5)-(6/2)";
	printf("# 수식 변환하기 \n\n");
	printf(" 입력 중위식 = %s\n", express);
	// 중위식을 후위식으로 변환출력
	printf(" 출력 후위식 = ");
	inFix2postFix(express);
		
	getchar(); 
}