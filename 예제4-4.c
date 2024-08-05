#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;		// ���� ����(element)�� �ڷ����� char�� ���� 

typedef struct  stackNode {	// ������ ��带 ����ü�� ����
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;				// ������ top ��带 �����ϱ� ���� ������ top ����

// ������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;     // ���� ��带 top�� ���� ����
	top = temp;           // top ��ġ�� ���� ���� �̵�
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;	// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);			// ������ ����� �޸� ��ȯ
		return item;		// ������ ���� ��ȯ
	}
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek() {
	if (isStackEmpty()) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		return(top->data);  // ���� top�� ���� ��ȯ
	}
}

// ������ ���Ҹ� top���� bottom ������ ����ϴ� ����
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

// �������� ���������� ��ȯ�ϴ� ����
void inFix2postFix(char* exp) {

	char symbol;
	int i, length = strlen(exp);
	top = NULL;
		
	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
			// (1) �ǿ������̸� ���
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			printf("%c", symbol);
			break;
			// (2) �������̸� push
		case '+':		case '-':		case '*':		case '/':
			push(symbol);  
			break;
		// 4) ���ȣ�̸� pop & ���
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
	printf("# ���� ��ȯ�ϱ� \n\n");
	printf(" �Է� ������ = %s\n", express);
	// �������� ���������� ��ȯ���
	printf(" ��� ������ = ");
	inFix2postFix(express);
		
	getchar(); 
}