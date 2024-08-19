#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义链表结构，包含尾指针和长度
typedef struct CircularLinkedList {
    Node* tail;  // 尾指针
    int length;  // 链表长度
} CircularLinkedList;

// 初始化循环单链表
CircularLinkedList* initCircularLinkedList() {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    list->tail = NULL;
    list->length = 0;
    return list;
}

// 在指定位置插入新节点 1:头部 -1:尾部
void insertNode(CircularLinkedList* list, int index, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (list->tail == NULL) {
        // 空链表
        list->tail = newNode;
        newNode->next = list->tail; // 指向自己
    } else {
        if (index == 1) {
            // 头部插入
            newNode->next = list->tail->next; // 新节点指向第一个节点
            list->tail->next = newNode; // 尾节点指向新节点
        } else if (index == -1 || index >= list->length) {
            // 尾部插入
            newNode->next = list->tail->next; // 新节点指向第一个节点
            list->tail->next = newNode; // 尾节点指向新节点
            list->tail = newNode; // 新节点成为尾节点
        } else {
            // 指定位置插入
            Node* temp = list->tail->next; // 指向第一个节点
            for (int i = 0; i < index - 1 && temp->next != list->tail->next; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    list->length++;
}

// 在头部插入新节点
void insertFirstNode(CircularLinkedList* list, int data) {
    insertNode(list, 1, data);
}

// 在尾部插入新节点
void insertLastNode(CircularLinkedList* list, int data) {
    insertNode(list, -1, data);
}

// 删除指定位置的节点
void deleteNode(CircularLinkedList* list, int index) {
    if (list->tail == NULL || index < 1 || index > list->length) return;

    Node* temp = list->tail->next;// 指向第一个节点
    if (index == 1) {
        // 删除第一个节点
        if (temp->next == list->tail->next) {
            // 只有一个节点的情况
            free(temp);
            list->tail = NULL;
        } else {
            list->tail->next = temp->next;
            free(temp);
        }
    } else {
        // 找到要删除位置的前一个节点
        for (int i = 0; i < index - 2 && temp->next != list->tail->next; i++) {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        if (delNode == list->tail) {
            list->tail = temp;
        }
        free(delNode);
    }
    list->length--;
}

// 遍历循环单链表
void traverseCircularLinkedList(CircularLinkedList* list) {
    if (list->tail == NULL) return;

    Node* temp = list->tail->next; // 指向第一个节点
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->tail->next);

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

    insertNode(L1, 2, 25);
    printf("\n链表内容:\n");
    traverseCircularLinkedList(L1);

    deleteNode(L1, 3);
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
