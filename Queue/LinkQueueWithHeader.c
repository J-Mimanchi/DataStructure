#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义队列
typedef struct Queue {
    Node* front; // 指向头节点
    Node* rear;  // 指向队列尾
} Queue;

// 初始化队列
void initQueue(Queue* queue) {
    Node* dummyNode = (Node*)malloc(sizeof(Node));// 头节点
    if (dummyNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    dummyNode->next = NULL;// 头节点的next指针指向NULL
    queue->front = queue->rear = dummyNode;// 头节点也是尾节点
}

// 判断队列是否为空
int isEmpty(Queue* queue) {
    return queue->front->next == NULL;
}

// 入队操作
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    queue->rear->next = newNode;// 尾节点的next指针指向新节点
    queue->rear = newNode;// 尾节点指向新节点
}

// 出队操作
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    Node* temp = queue->front->next;//跳过头节点
    int value = temp->data;
    queue->front->next = temp->next;// 头节点的next指针指向出队节点的下一个节点

    if (queue->rear == temp) {// 如果出队节点是尾节点
        //为什么要判断尾节点，因为如果队列只有一个元素，出队后，队列为空，需要将尾节点指向头节点
        queue->rear = queue->front;// 尾节点指向头节点

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
    return queue->front->next->data;
}

// 打印队列状态
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    Node* current = queue->front->next; // 跳过头节点
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
    free(queue->front); // 释放头节点
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
