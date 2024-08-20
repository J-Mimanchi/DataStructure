#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef int ElemType;  // 栈中元素的类型
typedef struct StackNode {
    ElemType data;  // 节点数据
    struct StackNode *next;  // 指向下一个节点的指针
} StackNode, *LinkStack;

// 初始化栈
void InitStack(LinkStack *S) {
    *S = NULL;  // 初始化时栈顶指针为空，表示空栈
}

// 判断栈是否为空
int StackEmpty(LinkStack S) {
    return S == NULL;
}

// 入栈操作
int Push(LinkStack *S, ElemType elem) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));  // 分配新节点空间
    if (newNode == NULL) {
        printf("内存分配失败，无法入栈\n");
        return 0;  // 入栈失败
    }
    newNode->data = elem;  // 设置新节点的数据
    newNode->next = *S;  // 新节点的下一个指针指向当前栈顶
    *S = newNode;  // 栈顶指针更新为新节点
    return 1;  // 入栈成功
}

// 出栈操作
int Pop(LinkStack *S, ElemType *elem) {
    if (StackEmpty(*S)) {
        printf("栈空，无法出栈\n");
        return 0;  // 出栈失败
    }
    StackNode *temp = *S;  // 临时指针指向当前栈顶
    *elem = temp->data;  // 获取栈顶元素
    *S = temp->next;  // 栈顶指针下移
    free(temp);  // 释放原栈顶节点空间
    return 1;  // 出栈成功
}

// 获取栈顶元素（不出栈）
int GetTop(LinkStack S, ElemType *elem) {
    if (StackEmpty(S)) {
        printf("栈空，无栈顶元素\n");
        return 0;  // 获取失败
    }
    *elem = S->data;  // 获取栈顶元素
    return 1;  // 获取成功
}

// 销毁栈（释放所有节点内存）
void DestroyStack(LinkStack *S) {
    StackNode *temp;
    while (*S) {
        temp = *S;
        *S = (*S)->next;
        free(temp);  // 逐个释放节点空间
    }
}

int main() {
    LinkStack stack;
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

    // 销毁栈
    DestroyStack(&stack);

    return 0;
}
