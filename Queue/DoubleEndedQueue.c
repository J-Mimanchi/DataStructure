#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 定义双端队列
typedef struct Deque {
    Node* front; // 队列头
    Node* rear;  // 队列尾
} Deque;

// 初始化双端队列
void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// 判断队列是否为空
int isEmpty(Deque* deque) {
    return deque->front == NULL;
}

// 从队头插入
void insertFront(Deque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = deque->front;// 新节点的后继指向原队头
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->rear = newNode;// 如果队列为空，新节点既是队头也是队尾
    } else {
        deque->front->prev = newNode;// 如果队列不为空，新节点成为队头，原队头的前驱指向新节点
    }
    deque->front = newNode;// 新节点成为队头
}

// 从队尾插入
void insertRear(Deque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = deque->rear;// 新节点的前驱指向原队尾

    if (isEmpty(deque)) {
        deque->front = newNode;// 如果队列为空，新节点既是队头也是队尾
    } else {
        deque->rear->next = newNode;// 如果队列不为空，新节点成为队尾，原队尾的后继指向新节点
    }
    deque->rear = newNode;// 新节点成为队尾
}

// 从队头删除
int deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }

    Node* temp = deque->front;
    int value = temp->data;
    deque->front = deque->front->next;// 队头指向下一个节点

    if (deque->front == NULL) {
        deque->rear = NULL;// 如果队头为空，队尾也为空
    } else {
        deque->front->prev = NULL;// 如果队头不为空，队头的前驱为空
    }

    free(temp);
    return value;
}

// 从队尾删除
int deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }

    Node* temp = deque->rear;
    int value = temp->data;
    deque->rear = deque->rear->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;// 如果队尾为空，队头也为空
    } else {
        deque->rear->next = NULL;// 如果队尾不为空，队尾的后继为空
    }

    free(temp);
    return value;
}

// 获取队头元素
int getFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->front->data;
}

// 获取队尾元素
int getRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->rear->data;
}

// 打印队列状态
void printDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    Node* current = deque->front;
    printf("Deque elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 释放双端队列内存
void freeDeque(Deque* deque) {
    while (!isEmpty(deque)) {
        deleteFront(deque);
    }
}

int main() {
    Deque deque;
    initDeque(&deque);
    printf("Deque initialized.\n\n");

    printf("Inserting 10 at the rear.\n");
    insertRear(&deque, 10);
    printDeque(&deque); // 输出队列状态

    printf("Inserting 20 at the front.\n");
    insertFront(&deque, 20);
    printDeque(&deque); // 输出队列状态

    printf("Inserting 30 at the rear.\n");
    insertRear(&deque, 30);
    printDeque(&deque); // 输出队列状态

    printf("\nCurrent front element: %d\n", getFront(&deque));
    printf("Current rear element: %d\n", getRear(&deque));

    printf("\nDeleting front element.\n");
    int deletedFront = deleteFront(&deque);
    printf("Deleted front element: %d\n", deletedFront);
    printDeque(&deque); // 输出队列状态

    printf("Deleting rear element.\n");
    int deletedRear = deleteRear(&deque);
    printf("Deleted rear element: %d\n", deletedRear);
    printDeque(&deque); // 输出队列状态

    printf("\nReleasing deque memory and cleaning up.\n");
    freeDeque(&deque);
    printf("Deque memory released.\n");

    return 0;
}

