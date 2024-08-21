#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5 // 定义队列的最大长度

typedef struct {
    int data[MAXSIZE]; // 存放队列元素的数组
    int front; // 队头指针
    int rear; // 队尾指针
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// 判断队列是否已满
int isFull(Queue *q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}

// 入队
int enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", x);
        return 0;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

// 出队
int dequeue(Queue *q, int *x) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return 0;
    }
    *x = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

// 获取队头元素
int getFront(Queue *q, int *x) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return 0;
    }
    *x = q->data[q->front];
    return 1;
}

// 打印队列状态
void printQueueStatus(Queue *q) {
    printf("Queue elements: ");
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->data[i]);
            i = (i + 1) % MAXSIZE;
        }
        printf("\n");
    }
    printf("Front index: %d\n", q->front);
    printf("Rear index: %d\n", q->rear);
    printf("Queue is %s\n", isEmpty(q) ? "empty" : "not empty");
    printf("Queue is %s\n", isFull(q) ? "full" : "not full");
    printf("-----------------------\n");
}

int main() {
    Queue q;
    initQueue(&q);

    printf("Initial queue status:\n");
    printQueueStatus(&q);

    printf("Enqueue 10:\n");
    enqueue(&q, 10);
    printQueueStatus(&q);

    printf("Enqueue 20:\n");
    enqueue(&q, 20);
    printQueueStatus(&q);

    printf("Enqueue 30:\n");
    enqueue(&q, 30);
    printQueueStatus(&q);

    printf("Dequeue:\n");
    int x;
    dequeue(&q, &x);
    printf("Dequeued element: %d\n", x);
    printQueueStatus(&q);

    printf("Enqueue 40:\n");
    enqueue(&q, 40);
    printQueueStatus(&q);

    printf("Enqueue 50:\n");
    enqueue(&q, 50);
    printQueueStatus(&q);

    printf("Attempting to enqueue 60 (should fail as queue is full):\n");
    enqueue(&q, 60);
    printQueueStatus(&q);

    printf("Dequeue:\n");
    dequeue(&q, &x);
    printf("Dequeued element: %d\n", x);
    printQueueStatus(&q);

    printf("Enqueue 60 (should succeed now):\n");
    enqueue(&q, 60);
    printQueueStatus(&q);

    printf("Final queue status:\n");
    printQueueStatus(&q);

    return 0;
}
