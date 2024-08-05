#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;             // ���� �����ڷ���  int 
typedef struct  stackNode { // ���ó�� ����ü
    element data;
    struct stackNode* link;
} stackNode;
stackNode* top;	//  top����������

// 1. ������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

// 2. ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
    stackNode* temp =
        (stackNode*)malloc(sizeof(stackNode));

    temp->data = item;
    temp->link = top;     // ���Գ�带 top ���� ����
    top = temp;           // top ��ġ�� ���� ���� �̵�
}
// 3. ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
    element item;
    stackNode* temp = top;

    if (isStackEmpty()) {// ������ ���� ����Ʈ�� ���
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {// ������ ���� ����Ʈ�� �ƴ� ���
        item = temp->data;
        top = temp->link;// top ��ġ�� ���� ��� �Ʒ��� �̵�
        free(temp);// ������ ����� �޸� ��ȯ
        return item;// ������ ���� ��ȯ
    }
}
// 4. ������ top ���Ҹ� �˻��ϴ� ����
element peek() {
    if (isStackEmpty()) {          // ������ ���� ������ ���
        printf("\n\n Stack is Empty !\n");
        return 0;
    }
    else return(top->data);       // ���� top�� ���� Ȯ��
}
// 5. ������ ���Ҹ� top���� bottom ������ ����ϴ� ����
void printStack() {
    stackNode* p = top;
    printf("\n STACK [ ");
    while (p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("] ");
}
// 6. �����Լ�
int main(void) {
    element item;
    top = NULL;
    printf("\n** ���� ���� ���� **\n");
    printStack();

    push(1);    printStack();		// 1 ����
    push(2);    printStack();		// 2 ����
    push(3);    printStack();		// 3 ����

    item = peek(); printStack();    // ���� top�� ���� ���
    printf("peek => %d", item);

    item = pop();  printStack();	// ����
    printf("\t pop  => %d", item);

    item = pop();  printStack();	// ����
    printf("\t pop  => %d", item);

    item = pop();  printStack();	// ����
    printf("\t pop  => %d\n", item);

    getchar();  return 0;
}
