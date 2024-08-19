#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct list {
    Node *head;
    int length;
} List;

void initList(List *list) {
    list->head = NULL;
    list->length = 0;
}

void freeList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->length = 0;
}

void printList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

void getElemByIndex(List *list, int index, int *num) {
    Node *current = list->head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {
        *num = current->data;
    } else {
        *num = -1;
    }
}

void getElemByValue(List *list, int num, int *index) {
    Node *current = list->head;
    int i = 0;
    while (current != NULL && current->data != num) {
        current = current->next;
        i++;
    }
    if (current != NULL) {
        *index = i + 1;
    } else {
        *index = -1;
    }
}

void insertList(List *list, int index, int num) {
    if (index < 1 || index > list->length + 1) {
        printf("\nIndex is illegal\n");
        return;
    }
    Node *current = list->head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;

    if (index == 1) {
        newNode->next = current;
        list->head = newNode;
        list->length++;
    } else {
        for (int i = 0; i < index - 2 && current != NULL; i++) {
            current = current->next;
        }
        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
            list->length++;
        }
    }
}

void deleteList(List *list, int index, int *num) {
    Node *current = list->head;

    if (index == 1) {
        list->head = current->next;
        *num = current->data;
        free(current);
        list->length--;
    } else {
        for (int i = 0; i < index - 2 && current != NULL; i++) {
            current = current->next;
        }
        Node *delNode = current->next;
        if (delNode != NULL) {
            current->next = delNode->next;
            *num = delNode->data;
            free(delNode);
            list->length--;
        }
    }
}

void headInsert(List *list, int num) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
}

void tailInsert(List *list, int num) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;
    Node *current = list->head;
    if (current == NULL) {
        list->head = newNode;
        list->length++;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        list->length++;
    }
}

int main() {
    List list1;
    List list2;

    initList(&list1);
    initList(&list2);

    headInsert(&list1, 1);
    headInsert(&list1, 2);
    headInsert(&list1, 3);
    headInsert(&list1, 4);
    printList(&list1);

    int num1;
    getElemByIndex(&list1, 3, &num1);
    printf("The 3rd element is %d\n", num1);

    getElemByValue(&list1, 4, &num1);
    printf("The index of 4 is %d\n", num1);

    printf("Insert 7 at index 2\n");
    insertList(&list1, 2, 7);
    printList(&list1);

    deleteList(&list1, 3, &num1);
    printf("The deleted element is %d\n", num1);
    printList(&list1);

    freeList(&list1);

    printf("=====================================\n");

    tailInsert(&list2, 4);
    tailInsert(&list2, 5);
    tailInsert(&list2, 6);
    tailInsert(&list2, 7);

    printList(&list2);

    int num2;
    getElemByIndex(&list2, 3, &num2);
    printf("The 3rd element is %d\n", num2);

    getElemByValue(&list2, 4, &num2);
    printf("The index of 4 is %d\n", num2);

    printf("Insert 7 at index 2\n");
    insertList(&list2, 2, 7);
    printList(&list2);

    deleteList(&list2, 3, &num2);
    printf("The deleted element is %d\n", num2);
    printList(&list2);

    freeList(&list2);
    return 0;
}
