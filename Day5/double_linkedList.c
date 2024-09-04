/*
Write a program to create a double linked list and perform the following menu based operations on it:
i.insert an element at specific position 
ii.delete an element from specific position 
iii.Traverse the list
*/

#include<stdlib.h>
#include<stdio.h>

struct node{
    struct node*prev;
    int data;
    struct node*next;
};
struct node*head = NULL;

void randinsert(int n, int loc){
    struct node*ptr = (struct node*)malloc(sizeof(struct node)),
    *temp = head;
    if(ptr == NULL){
        printf("Overflow\n");
        return;
    }
    ptr->data = n;
    if(head == NULL){
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
        printf("Node Inserted\n");
        return;
    }
    if(loc == 0){
        ptr->next = head;
        ptr->prev = NULL;
        head->prev=ptr;
        head=ptr;
        printf("Node Inserted\n");
        return;
    }
    for(int i=0;i<loc-1;i++){
        if(temp==NULL){
            printf("Invalid position\n");
            free(ptr);
            return;
        }
        temp=temp->next;
    }
    if(temp->next == NULL){
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
    }
    else{
        ptr->next=temp->next;
        temp->next->prev=ptr;
        temp->next=ptr;
        ptr->prev=temp;
    }
    printf("Node Inserted\n");
}
void randdel(int loc) {
    struct node*temp=head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(loc == 0){
        head=temp->next;
        if(head != NULL){
            head->prev=NULL;
        }    
        free(temp);
        printf("Node Deleted\n");
        return;
    }
    for(int i=0;i<loc;i++){
        if(temp == NULL){
            printf("Invalid Position\n");
            return;
        }
        temp=temp->next;
    }
    if(temp->next == NULL){
        temp->prev->next=NULL;
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    } 
    free(temp);
    printf("Node Deleted\n");
}
void traversal() {
    struct node*temp = head;
    while(temp != NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int n,num,loc,choice=0;
    printf("Enter the size of list: ");
    scanf("%d",&n); 
    if(n>0){
        head = (struct node*)malloc(sizeof(struct node));
        if(head == NULL){
            printf("Overflow\n");
            return 1;
        }
        printf("Element 1: ");
        scanf("%d",&(head->data));
        head->prev = NULL;
        head->next = NULL;
        struct node*temp = head ;
        for(int i = 1;i < n;i++) {
            struct node*ptr = (struct node*)malloc(sizeof(struct node));
            if(ptr == NULL){
                printf("Overflow\n");
                return 1;
            }
            printf("Element %d: ",i+1);
            scanf("%d",&(ptr->data));
            temp->next=ptr;
            ptr->next = NULL;
            ptr->prev = temp;
            temp = ptr;
        }
    }
    while(1) {
        printf("Main Menu\n");
        printf("1. Insertion 2.Deletion 3.Traversal 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                printf("Enter the element: ");
                scanf("%d",&num);
                printf("Enter the location: ");
                scanf("%d",&loc);
                randinsert(num,loc);
                break;
            }
            case 2: {
                printf("Enter the location: ");
                scanf("%d",&loc);
                randdel(loc);
                break;
            }
            case 3: traversal();break;
            case 4: printf("Exiting....\n");exit(1);break;
            default: printf("Please enter the valid option\n");
        }
    }
    return 0;
}