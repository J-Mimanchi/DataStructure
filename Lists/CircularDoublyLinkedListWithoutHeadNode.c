#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// 定义链表结构，包含尾节点指针和长度
typedef struct CircularDoublyLinkedList {
    Node* tail;  // 尾节点指针
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
    list->tail = NULL;  // 初始化为空
    list->length = 0;
    return list;
}

// 在指定位置插入新节点
void insertNode(CircularDoublyLinkedList* list, int index, int data) {
    if (index < 1 || index > list->length + 1) {
        printf("插入位置不合法\n");
        return;
    }

    Node* newNode = createNode(data);
    if (list->tail == NULL) {
        // 如果链表为空，新节点成为唯一节点
        list->tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Node* temp;
        if (index == 1) {
            // 在头部插入节点
            temp = list->tail->next; // 头节点
            newNode->next = temp;
            newNode->prev = list->tail;
            temp->prev = newNode;// 头节点的prev指向新节点
            list->tail->next = newNode; // 尾节点的next指向新节点
        } else if (index == list->length + 1) {
            // 在尾部插入节点
            temp = list->tail;
            newNode->next = temp->next;  // 指向头节点
            newNode->prev = temp;
            temp->next->prev = newNode;// 头节点的prev指向新节点
            temp->next = newNode;// 尾节点的next指向新节点
            list->tail = newNode;  // 更新尾节点
        } else {
            // 在中间插入节点
            temp = list->tail->next;// 头节点
            for (int i = 1; i < index - 1; i++) {// 找到要插入位置的前一个节点
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
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

    Node* temp;
    if (list->length == 1) {
        // 只有一个节点的情况
        temp = list->tail;
        list->tail = NULL;
    } else {
        if (index == 1) {
            // 删除头节点
            temp = list->tail->next;
            list->tail->next = temp->next;
            temp->next->prev = list->tail;
        } else if (index == list->length) {
            // 删除尾节点
            temp = list->tail;
            list->tail->prev->next = list->tail->next;
            list->tail->next->prev = list->tail->prev;
            list->tail = list->tail->prev;  // 更新尾节点
        } else {
            // 删除中间节点
            temp = list->tail->next;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
    free(temp);
    list->length--;
}

// 遍历循环双链表
void traverseCircularDoublyLinkedList(CircularDoublyLinkedList* list) {
    if (list->length == 0) {
        printf("链表为空\n");
        return;
    }

    Node* temp = list->tail->next;  // 从头节点开始
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->tail->next);
    printf("\n链表长度: %d\n", list->length);
}

// 逆向遍历循环双链表
void reverseTraverseCircularDoublyLinkedList(CircularDoublyLinkedList* list) {
    if (list->length == 0) {
        printf("链表为空\n");
        return;
    }

    Node* temp = list->tail;  // 从尾节点开始
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != list->tail);
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
