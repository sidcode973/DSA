#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createLinkedList() {
    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
  
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter element at node 1: ");
    scanf("%d", &(head->data));
    head->next = NULL;
    struct Node* p = head;
    for (int i = 1; i < n; i++) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter element at node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->data = data;
    if (index == 1) {
        ptr->next = head;
        return ptr;
    }
    struct Node* p = head;
    for (int i = 1; i < index - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Position out of range\n");
        free(ptr);
        return head;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int index) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* p = head;
    if (index == 1) {
        head = head->next;
        free(p);
        return head;
    }
    for (int i = 1; i < index - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL || p->next == NULL) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = createLinkedList();
    int choice, data, index;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at specific index\n");
        printf("2. Delete a node at specific index\n");
        printf("3. Count nodes\n");
        printf("4. Traverse the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the index: ");
                scanf("%d", &index);
                head = insertAtPosition(head, data, index);
                break;
            case 2:
                printf("Enter the index of the node to be deleted: ");
                scanf("%d", &index);
                head = deleteAtPosition(head, index);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                printf("Linked list: ");
                traverseList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}