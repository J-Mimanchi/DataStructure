#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义队列
typedef struct Queue {
    Node* front; // 队列头
    Node* rear;  // 队列尾
} Queue;

// 初始化队列
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 判断队列是否为空
int isEmpty(Queue* queue) {
    return queue->front == NULL;// 队头为空则队列为空
}

// 入队操作
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));// 为新节点分配内存
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;// 队列为空时，新节点即为队头也为队尾
    } else {
        queue->rear->next = newNode;// 队尾节点的next指向新节点
        queue->rear = newNode;// 队尾指针指向新节点
    }
}

// 出队操作
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;// 队头为空时，队尾也为空
    }

    free(temp);
    return value;
}

// 获取队列头元素
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// 打印队列状态
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    Node* current = queue->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 释放队列内存
void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    printQueue(&queue); // 输出队列状态

    enqueue(&queue, 20);
    printQueue(&queue); // 输出队列状态

    enqueue(&queue, 30);
    printQueue(&queue); // 输出队列状态

    printf("Front element is %d\n", front(&queue));

    printf("Dequeue element: %d\n", dequeue(&queue));
    printQueue(&queue); // 输出队列状态

    printf("Dequeue element: %d\n", dequeue(&queue));
    printQueue(&queue); // 输出队列状态

    enqueue(&queue, 40);
    printQueue(&queue); // 输出队列状态

    printf("Front element is %d\n", front(&queue));

    freeQueue(&queue);

    return 0;
}
