#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义链表结构，包含头指针和长度
typedef struct CircularLinkedList {
    Node* head;  // 头指针
    int length;  // 链表长度
} CircularLinkedList;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 初始化循环单链表
CircularLinkedList* initCircularLinkedList() {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    list->head = createNode(-1); // 创建头节点
    list->head->next = list->head;  // 指向自身形成环
    list->length = 0;
    return list;
}

// 指定位置插入新节点
void insertNode(CircularLinkedList* list, int index, int data) {
    if (index < 1 || index > list->length + 1) {
        printf("插入位置不合法\n");
        return;
    }

    Node* newNode = createNode(data);
    Node* temp = list->head;

    if(index == 1) {
        // 头部插入
        newNode->next = temp->next;
        temp->next = newNode;
        list->length++;
        return;
    }
    for (int i = 0; i < index -1; i++) {  // 找到要插入位置
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    list->length++;
}

// 在头部插入新节点
void insertFirstNode(CircularLinkedList* list, int data) {
    insertNode(list, 1, data);
}

// 在尾部插入新节点
void insertLastNode(CircularLinkedList* list, int data) {
    insertNode(list, list->length + 1, data);
}

// 删除指定位置的节点
void deleteNode(CircularLinkedList* list, int index) {
    if (index < 1 || index > list->length) {
        printf("删除位置不合法\n");
        return;
    }

    Node* temp = list->head;
    for (int i = 0; i < index - 1; i++) {  // 找到要删除位置的前一个节点
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    list->length--;
}

// 遍历循环单链表
void traverseCircularLinkedList(CircularLinkedList* list) {
    if (list->length == 0) {
        printf("链表为空\n");
        return;
    }

    Node* temp = list->head->next;  // 跳过头节点
    printf("(head)-> ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n链表长度: %d\n", list->length);
}

// 主函数示例
int main() {
    CircularLinkedList* L1 = initCircularLinkedList();
    insertLastNode(L1, 20);
    insertLastNode(L1, 30);
    insertLastNode(L1, 40);

    printf("\n链表内容:\n");
    traverseCircularLinkedList(L1);

    deleteNode(L1, 1);
    printf("\n链表内容:\n");
    traverseCircularLinkedList(L1);

    insertNode(L1, 1, 25);
    printf("\n链表内容:\n");
    traverseCircularLinkedList(L1);

    printf("\n=====================================\n");
    CircularLinkedList* L2 = initCircularLinkedList();
    insertFirstNode(L2, 10);
    insertFirstNode(L2, 5);
    insertFirstNode(L2, 0);

    printf("\n链表内容:\n");
    traverseCircularLinkedList(L2);

    return 0;
}
