#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// 定义链表结构，包含头指针和长度
typedef struct CircularDoublyLinkedList {
    Node* head;  // 头指针
    int length;  // 链表长度
} CircularDoublyLinkedList;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 初始化循环双链表
CircularDoublyLinkedList* initCircularDoublyLinkedList() {
    CircularDoublyLinkedList* list = (CircularDoublyLinkedList*)malloc(sizeof(CircularDoublyLinkedList));
    list->head = createNode(-1); // 创建头节点
    list->head->next = list->head; // 头节点的next和prev都指向自身
    list->head->prev = list->head;
    list->length = 0;
    return list;
}

// 指定位置插入新节点
void insertNode(CircularDoublyLinkedList* list, int index, int data) {
    if (index < 1 || index > list->length + 1) {
        printf("插入位置不合法\n");
        return;
    }

    Node* newNode = createNode(data);
    Node* temp = list->head;
    for (int i = 0; i < index - 1; i++) {  // 找到要插入位置的前一个节点
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    list->length++;
}

// 在头部插入新节点
void insertFirstNode(CircularDoublyLinkedList* list, int data) {
    insertNode(list, 1, data);
}

// 在尾部插入新节点
void insertLastNode(CircularDoublyLinkedList* list, int data) {
    insertNode(list, list->length + 1, data);
}

// 删除指定位置的节点
void deleteNode(CircularDoublyLinkedList* list, int index) {
    if (index < 1 || index > list->length) {
        printf("删除位置不合法\n");
        return;
    }

    Node* temp = list->head;
    for (int i = 0; i < index; i++) {  // 找到要删除的节点
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    list->length--;
}

// 遍历循环双链表
void traverseCircularDoublyLinkedList(CircularDoublyLinkedList* list) {
    if (list->length == 0) {
        printf("链表为空\n");
        return;
    }

    Node* temp = list->head->next;  // 跳过头节点
    printf("(head) ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n链表长度: %d\n", list->length);
}

// 逆向遍历循环双链表
void reverseTraverseCircularDoublyLinkedList(CircularDoublyLinkedList* list) {
    if (list->length == 0) {
        printf("链表为空\n");
        return;
    }

    Node* temp = list->head->prev;  // 最后一个节点
    printf("(head) ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != list->head);
    printf("\n链表长度: %d\n", list->length);
}

// 主函数示例
int main() {
    CircularDoublyLinkedList* L1 = initCircularDoublyLinkedList();
    insertLastNode(L1, 20);
    insertLastNode(L1, 30);
    insertLastNode(L1, 40);

    printf("\n链表内容:\n");
    traverseCircularDoublyLinkedList(L1);

    deleteNode(L1, 1);
    printf("\n链表内容:\n");
    traverseCircularDoublyLinkedList(L1);

    insertNode(L1, 1, 25);
    printf("\n链表内容:\n");
    traverseCircularDoublyLinkedList(L1);

    printf("\n逆向链表内容:\n");
    reverseTraverseCircularDoublyLinkedList(L1);

    printf("\n=====================================\n");
    CircularDoublyLinkedList* L2 = initCircularDoublyLinkedList();
    insertFirstNode(L2, 10);
    insertFirstNode(L2, 5);
    insertFirstNode(L2, 0);

    printf("\n链表内容:\n");
    traverseCircularDoublyLinkedList(L2);

    printf("\n逆向链表内容:\n");
    reverseTraverseCircularDoublyLinkedList(L2);

    return 0;
}
