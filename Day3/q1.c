

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;


Node *createLinkedList()
{
    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    Node *head = (Node *)malloc(sizeof(Node));
    printf("Enter element at node 1: ");
    scanf("%d", &(head->data));
    head->next = NULL;
    Node *p = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        printf("Enter element at node %d : ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        p->next = temp;
        p = p->next; 
    }
    return head;
}


void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


Node *insertAtEnd(Node *head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the value to be inserted at end: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}


Node *insertAtBeginning(Node *head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the value to be inserted at beginning: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    return head;
}


Node *insertAtPosition(Node *head, int pos)
{
    if (pos == 1)
    {
        insertAtBeginning(head);
        return head;
    }
    if (pos<1)
    {
        printf("Invalid Position\n");
        return head;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the value to be inserted at position %d: ", pos);
    scanf("%d", &newNode->data);
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp!=NULL; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}


int main()
{
    Node *head = createLinkedList();
    traverseLL(head);

    int choice;
    while (1)
    {
        printf("\nMENU:\n");
        printf("1. Traverse the linked list\n");
        printf("2. Insert an element at the end\n");
        printf("3. Insert an element in the beginning\n");
        printf("4. Insert an element at any position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    switch (choice){
        case 1:{
            printf("Linked List: ");
            traverseLL(head);
            break;}
        case 2:{
            head = insertAtEnd(head);
            printf("Linked List after insertion: ");
            traverseLL(head);
            break;}
        case 3:{
            head = insertAtBeginning(head);
            printf("Linked List after insertion: ");
            traverseLL(head);
            break;}
        case 4:{
            int pos;
            printf("Enter the position you want to insert the element at: ");
            scanf("%d",&pos);
            head = insertAtPosition(head, pos);
            printf("Linked List after insertion: ");
            traverseLL(head);
            break;}
        case 5:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}