#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 栈的最大容量

typedef int ElemType;  // 栈中元素的类型
typedef struct {
    ElemType data[MAX_SIZE];  // 存储栈中元素的数组
    int top;  // 栈顶指针，指向栈顶元素
} SqStack;

// 初始化栈
void InitStack(SqStack *S) {
    S->top = -1;  // 栈顶指针初始化为-1，表示空栈
}

// 判断栈是否为空
int StackEmpty(SqStack S) {
    return S.top == -1;
}

// 判断栈是否满
int StackFull(SqStack S) {
    return S.top == MAX_SIZE - 1;
}

// 入栈操作
int Push(SqStack *S, ElemType elem) {
    if (StackFull(*S)) {
        printf("栈满，无法入栈\n");
        return 0;  // 入栈失败
    }
    S->data[++(S->top)] = elem;  // 将元素压入栈顶，栈顶指针上移
    return 1;  // 入栈成功
}

// 出栈操作
int Pop(SqStack *S, ElemType *elem) {
    if (StackEmpty(*S)) {
        printf("栈空，无法出栈\n");
        return 0;  // 出栈失败
    }
    *elem = S->data[(S->top)--];  // 将栈顶元素弹出，栈顶指针下移
    return 1;  // 出栈成功
}

// 获取栈顶元素（不出栈）
int GetTop(SqStack S, ElemType *elem) {
    if (StackEmpty(S)) {
        printf("栈空，无栈顶元素\n");
        return 0;  // 获取失败
    }
    *elem = S.data[S.top];  // 获取栈顶元素
    return 1;  // 获取成功
}

int main() {
    SqStack stack;
    InitStack(&stack);

    // 测试入栈
    for (int i = 0; i < 5; i++) {
        Push(&stack, i + 1);
    }

    // 获取栈顶元素
    ElemType topElem;
    if (GetTop(stack, &topElem)) {
        printf("栈顶元素为: %d\n", topElem);
    }

    // 测试出栈
    ElemType elem;
    while (!StackEmpty(stack)) {
        Pop(&stack, &elem);
        printf("出栈元素: %d\n", elem);
    }

    return 0;
}
