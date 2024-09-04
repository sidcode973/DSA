#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node *createLinkedList() {
    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    if (n <= 0) return NULL;

    Node *head = (Node *)malloc(sizeof(Node));
    printf("Enter element at node 1: ");
    scanf("%d", &(head->data));
    head->next = NULL;

    Node *p = head;
    for (int i = 1; i < n; i++) {
        Node *temp = (Node *)malloc(sizeof(Node));
        printf("Enter element at node %d : ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
    return head;
}


void traverseLL(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}


void searchElement(Node *head, int key) {
    Node *p = head;
    int pos = 1;
    while (p != NULL) {
        if (p->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("Element %d not found in the list\n", key);
}


Node* sortLinkedList(Node *head) {
    if (!head) return NULL;

    Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}


Node* reverseLinkedList(Node *head) {
    Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    Node *head = createLinkedList();
    int choice, key;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Search the element\n");
        printf("2. Sort the list in ascending order\n");
        printf("3. Reverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchElement(head, key);
                break;
            case 2:
                head = sortLinkedList(head);
                printf("Linked List after sorting: ");
                traverseLL(head);
                break;
            case 3:
                head = reverseLinkedList(head);
                printf("Linked List after reversing: ");
                traverseLL(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
