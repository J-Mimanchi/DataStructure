#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // 用于字符处理函数
#include <string.h>

#define MAX 100

// 栈结构体定义
typedef struct Stack {
    int top;
    int items[MAX];  // 改为存储整数
} Stack;

// 初始化栈
void init(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void printStack(Stack *s);

// 压栈操作
void push(Stack *s, int item) {  // 直接存储整数
    if (isFull(s)) {
        printf("栈满了，无法压入'%d'\n", item);
        exit(1);
    } else {
        s->items[++s->top] = item;
        printf("将 '%d' 压入栈中\n", item);
        printStack(s);
    }
}

// 出栈操作
int pop(Stack *s) {  // 返回整数
    if (isEmpty(s)) {
        printf("栈空了，无法弹出元素\n");
        exit(1);
    } else {
        int item = s->items[s->top--];
        printf("从栈中弹出 '%d'\n", item);
        printStack(s);
        return item;
    }
}

// 获取栈顶元素
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("栈是空的\n");
        exit(1);
    } else {
        return s->items[s->top];
    }
}

// 打印栈的当前状态
void printStack(Stack *s) {
    printf("当前栈状态: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// 判断字符是否为操作符
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 获取操作符的优先级
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// 中缀表达式转换为后缀表达式
void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    init(&stack);
    int i = 0, j = 0;
    char ch;

    printf("转换中缀表达式为后缀表达式的步骤:\n");

    while ((ch = infix[i++]) != '\0') {
        // 如果是操作数，直接添加到后缀表达式中
        if (isalnum(ch)) {
            postfix[j++] = ch;
            printf("遇到操作数 '%c'，直接加入后缀表达式: %s\n", ch, postfix);
        }
        // 如果是左括号，压入栈中
        else if (ch == '(') {
            push(&stack, ch);
        }
        // 如果是右括号，弹出栈中的元素，直到遇到左括号
        else if (ch == ')') {
            printf("遇到右括号 '%c'，开始弹出栈中的元素直到遇到左括号\n", ch);
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
                printf("弹出操作符 '%c'，后缀表达式: %s\n", postfix[j-1], postfix);
            }
            pop(&stack);  // 弹出左括号
        }
        // 如果是操作符
        else if (isOperator(ch)) {
            printf("遇到操作符 '%c'，开始处理操作符优先级\n", ch);
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
                printf("弹出操作符 '%c'，后缀表达式: %s\n", postfix[j-1], postfix);
            }
            push(&stack, ch);
        }
    }

    // 弹出栈中剩余的操作符
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
        printf("弹出操作符 '%c'，后缀表达式: %s\n", postfix[j-1], postfix);
    }

    postfix[j] = '\0';  // 添加字符串结束符
}

// 计算后缀表达式的值
int evaluatePostfix(char postfix[]) {
    Stack stack;
    init(&stack);
    int i = 0;
    char ch;
    int val1, val2;

    printf("计算后缀表达式 '%s' 的步骤:\n", postfix);

    while ((ch = postfix[i++]) != '\0') {
        // 如果是操作数，压入栈中
        if (isdigit(ch)) {
            push(&stack, ch - '0');  // 将字符转换为整数并存储
        }
        // 如果是操作符，弹出两个操作数并进行运算
        else if (isOperator(ch)) {
            val2 = pop(&stack);
            val1 = pop(&stack);
            int result;
            switch (ch) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;
            }
            printf("计算 %d %c %d = %d，并将结果 '%d' 压入栈中\n", val1, ch, val2, result, result);
            push(&stack, result);
        }
    }

    // 返回栈顶元素，即表达式的值
    int finalResult = pop(&stack);
    printf("最终结果为: %d\n", finalResult);
    return finalResult;
}

int main() {
    char infix[MAX]={0}, postfix[MAX]={0};

    printf("请输入一个中缀表达式: ");
    fgets(infix, MAX, stdin);
    // 移除fgets输入的换行符
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("转换后的后缀表达式为: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("该表达式的计算结果为: %d\n", result);

    return 0;
}
