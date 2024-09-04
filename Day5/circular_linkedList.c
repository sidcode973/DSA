#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
    
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    return head;
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n") ;
        return;
    }
    struct Node* temp = head;
    printf("%d -> ", temp->data) ;
    temp = temp->next;
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", head->data);  
}

int main() {
    struct Node* head = NULL;
    int n, data;

    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = append(head, data);
    }

    
    printf("Elements in the circular linked list:\n");
    display(head);

    return 0;
}
