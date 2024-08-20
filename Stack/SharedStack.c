#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 栈的最大容量

typedef int ElemType;  // 栈中元素的类型
typedef struct {
    ElemType data[MAX_SIZE];  // 存储栈中元素的数组
    int top1;  // 栈1的栈顶指针
    int top2;  // 栈2的栈顶指针
} SharedStack;

// 初始化共享栈
void InitStack(SharedStack *S) {
    S->top1 = -1;  // 栈1从数组的起始位置开始
    S->top2 = MAX_SIZE;  // 栈2从数组的末尾位置开始
}

// 判断栈1是否为空
int Stack1Empty(SharedStack S) {
    return S.top1 == -1;
}

// 判断栈2是否为空
int Stack2Empty(SharedStack S) {
    return S.top2 == MAX_SIZE;
}

// 判断共享栈是否满
int StackFull(SharedStack S) {
    return S.top1 + 1 == S.top2;
}

// 栈1入栈操作
int Push1(SharedStack *S, ElemType elem) {
    if (StackFull(*S)) {
        printf("栈满，无法入栈1\n");
        return 0;  // 入栈失败
    }
    S->data[++(S->top1)] = elem;  // 将元素压入栈1的栈顶
    return 1;  // 入栈成功
}

// 栈2入栈操作
int Push2(SharedStack *S, ElemType elem) {
    if (StackFull(*S)) {
        printf("栈满，无法入栈2\n");
        return 0;  // 入栈失败
    }
    S->data[--(S->top2)] = elem;  // 将元素压入栈2的栈顶
    return 1;  // 入栈成功
}

// 栈1出栈操作
int Pop1(SharedStack *S, ElemType *elem) {
    if (Stack1Empty(*S)) {
        printf("栈1空，无法出栈\n");
        return 0;  // 出栈失败
    }
    *elem = S->data[(S->top1)--];  // 将栈1的栈顶元素弹出
    return 1;  // 出栈成功
}

// 栈2出栈操作
int Pop2(SharedStack *S, ElemType *elem) {
    if (Stack2Empty(*S)) {
        printf("栈2空，无法出栈\n");
        return 0;  // 出栈失败
    }
    *elem = S->data[(S->top2)++];  // 将栈2的栈顶元素弹出
    return 1;  // 出栈成功
}

// 获取栈1的栈顶元素（不出栈）
int GetTop1(SharedStack S, ElemType *elem) {
    if (Stack1Empty(S)) {
        printf("栈1空，无栈顶元素\n");
        return 0;  // 获取失败
    }
    *elem = S.data[S.top1];  // 获取栈1的栈顶元素
    return 1;  // 获取成功
}

// 获取栈2的栈顶元素（不出栈）
int GetTop2(SharedStack S, ElemType *elem) {
    if (Stack2Empty(S)) {
        printf("栈2空，无栈顶元素\n");
        return 0;  // 获取失败
    }
    *elem = S.data[S.top2];  // 获取栈2的栈顶元素
    return 1;  // 获取成功
}

int main() {
    SharedStack stack;
    InitStack(&stack);

    // 测试栈1入栈
    for (int i = 0; i < 5; i++) {
        Push1(&stack, i + 1);
    }

    // 测试栈2入栈
    for (int i = 0; i < 5; i++) {
        Push2(&stack, i + 6);
    }

    // 获取栈1和栈2的栈顶元素
    ElemType topElem;
    if (GetTop1(stack, &topElem)) {
        printf("栈1栈顶元素为: %d\n", topElem);
    }
    if (GetTop2(stack, &topElem)) {
        printf("栈2栈顶元素为: %d\n", topElem);
    }

    // 测试栈1出栈
    ElemType elem;
    while (!Stack1Empty(stack)) {
        Pop1(&stack, &elem);
        printf("栈1出栈元素: %d\n", elem);
    }

    // 测试栈2出栈
    while (!Stack2Empty(stack)) {
        Pop2(&stack, &elem);
        printf("栈2出栈元素: %d\n", elem);
    }

    return 0;
}
