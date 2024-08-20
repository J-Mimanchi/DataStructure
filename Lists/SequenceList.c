#include <stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct {
    int *data;
    int length;
} SqList;

void initList(SqList *list) {
    list->data = (int*)malloc(sizeof(int) * MAX);
    list->length = 0;
}

void destroyList(SqList *list) {
    free(list->data);
    list->length = 0;
}

void printList(SqList list) {
    for(int i = 0; i < list.length; i++) {
        printf("%d\t", list.data[i]);
    }
    printf("\n");
}

void createList(SqList *list, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &list->data[i]);
        list->length++;
    }
}

void insertList(SqList *list, int index, int element) {
    for(int j = list->length; j >= index; j--) {
        list->data[j] = list->data[j - 1];
    }
    list->data[index - 1] = element;
    list->length++;
}

void deleteListByIndex(SqList *list, int index, int *element) {
    *element = list->data[index - 1];
    for(int i = index; i < list->length; i++) {
        list->data[i - 1] = list->data[i];
    }
    list->length--;
}

void deleteListByElement(SqList *list, int element) {
    for(int i = 0; i < list->length; i++) {
        if(list->data[i] == element) {
            for(int j = i; j < list->length - 1; j++) {
                list->data[j] = list->data[j + 1];
            }
            break;
        }
    }
    list->length--;
}

void updateList(SqList *list, int index, int element) {
    list->data[index - 1] = element;
}

void searchListByElement(SqList list, int element, int* index) {
    *index = -1;
    for(int i = 0; i < list.length; i++) {
        if(list.data[i] == element) {
            *index = i;
        }
    }
}

void searchListByIndex(SqList list, int index, int* element) {
    if(index >= 0 && index < list.length) {
        *element = list.data[index];
    } else {
        *element = -1;
    }
}

int main() {
    SqList list;
    initList(&list);
    createList(&list, 5);
    printf("\nInitialized list:\n");
    printList(list);

    printf("\nAfter insert:\n");
    insertList(&list, 3, 10);
    printList(list);

    int *element = (int *)malloc(sizeof(int));

    deleteListByIndex(&list, 3, element);
    printf("\nAfter delete by index:\n");
    printList(list);
    printf("\nDeleted element: %d\n", *element);

    deleteListByElement(&list, 1);
    printf("\nAfter delete by element:\n");
    printList(list);

    updateList(&list, 3, 20);
    printf("\nAfter update:\n");
    printList(list);

    int searchNum = 5;
    int *index = (int *)malloc(sizeof(int));
    searchListByElement(list, searchNum, index);
    printf("\nSearch by element %d success, index is %d\n", searchNum, *index);

    int searchIndex = 3;
    searchListByIndex(list, searchIndex, element);
    if(*element != -1) {
        printf("\nSearch by index %d success, element is %d\n", searchIndex, *element);
    }

    destroyList(&list);
    free(element);
    free(index);

    return 0;
}
