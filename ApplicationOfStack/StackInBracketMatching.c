#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// 栈结构体定义
typedef struct Stack {
    int top;
    char items[MAX];
} Stack;

// 初始化栈
void init(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

// 压栈操作
void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("栈满了，无法压入'%c'\n", item);
        exit(1);
    } else {
        s->items[++s->top] = item;
        printf("将'%c'压入栈中。当前栈内容: ", item);
        for (int i = 0; i <= s->top; i++) {
            printf("%c ", s->items[i]);
        }
        printf("\n");
    }
}

// 出栈操作
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("栈空了，无法弹出元素\n");
        exit(1);
    } else {
        char item = s->items[s->top--];
        printf("将'%c'从栈中弹出。当前栈内容: ", item);
        for (int i = 0; i <= s->top; i++) {
            printf("%c ", s->items[i]);
        }
        printf("\n");
        return item;
    }
}

// 检查括号是否匹配
bool isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return true;
    else if (char1 == '{' && char2 == '}') return true;
    else if (char1 == '[' && char2 == ']') return true;
    return false;
}

// 检查表达式中的括号是否匹配
bool areParenthesesBalanced(char exp[]) {
    int i = 0;
    Stack stack;// 创建一个栈
    init(&stack);// 初始化栈

    while (exp[i]) {
        // 如果是开括号，压入栈中
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            printf("遇到开括号'%c'\n", exp[i]);
            push(&stack, exp[i]);
        }

        // 如果是闭括号，检查是否匹配
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            printf("遇到闭括号'%c'\n", exp[i]);

            // 如果栈为空，则表示没有匹配的开括号
            if (isEmpty(&stack)) {
                printf("没有匹配的开括号来匹配'%c'\n", exp[i]);
                return false;
            }
            // 出栈并检查是否匹配
            else {
                char popped = pop(&stack);
                if (!isMatchingPair(popped, exp[i])) {
                    printf("不匹配: '%c' 与 '%c' 不匹配\n", popped, exp[i]);
                    return false;
                } else {
                    printf("匹配成功: '%c' 与 '%c' 匹配\n", popped, exp[i]);
                }
            }
        }
        i++;
    }

    // 如果栈为空，说明所有括号匹配正确
    if (isEmpty(&stack)) {
        printf("所有括号匹配成功。\n");
        return true;
    } else {
        printf("栈中仍有未匹配的开括号。\n");
        return false;
    }
}

int main() {
    char expression[MAX];

    printf("请输入一个表达式: ");
    gets(expression);  // 输入表达式

    if (areParenthesesBalanced(expression))
        printf("括号匹配成功\n");
    else
        printf("括号匹配失败\n");

    return 0;
}
