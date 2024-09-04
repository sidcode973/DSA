//Write a program to create a circular linked list and display the elements of the list.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node*head;
void traverse() {
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node*temp = head;
    for(;;){
        printf("%d -> ",temp->data);
        temp = temp->next;
        if(temp == head){
            break;
        }
    }
    printf("HEAD\n");
}
int main(){
    int n;
    printf("Enter the size of list: ");
    scanf("%d",&n);
    if (n>0){
        head = (struct node*)malloc(sizeof(struct node));
        if(head == NULL){
            printf("Overflow\n");
            return 1;
        }
        printf("Element 1: ");
        scanf("%d",&(head->data));
        head->next = head;
        struct node*temp = head;
        for(int i = 1; i < n ; i++){
            struct node*ptr = (struct node*)malloc(sizeof(struct node));
            if (ptr == NULL) {
                printf("Overflow\n");
                return 1;
            }
            temp->next = ptr;
            printf("Element %d: ",i+1);
            scanf("%d",&(ptr->data));
            ptr->next = head;
            temp = ptr;
        }
        traverse();
    }
    return 0 ;
}