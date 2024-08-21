#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node*head;
void traverse(){
    struct node*temp;
    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void beginsert(){
    struct node*ptr;
    int element;
    ptr = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value:\n");
        scanf("%d",&element);
        ptr->data = element;
        ptr->next = head;
        head = ptr; 
        printf("Nodeinserted\n");
    
}
void lastinsert(){
    struct node*ptr,*temp;
    int element;
    ptr = (struct node*)malloc(sizeof(struct node));
      
      printf("Enter the value: ");
        scanf("%d",&element);
        ptr->data = element;
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
            printf("Node inserted\n");
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("Node Inserted\n");
        }
}
void insertAtPosition(){
    struct node * ptr,*temp;
    int element,location;
    ptr = (struct node*)malloc(sizeof(struct node));
    
        printf("Enter the value: ");
        scanf("%d",&element);
        printf("Enter the location: ");
        scanf("%d",&location);
        ptr->data = element;
        temp = head;
        if(location == 0){
            ptr->next = head;
            head = ptr;
            printf("Node is inserted at the head\n");
        }
        else{
            for(int i = 0; i<location-1;i++){
                temp=temp->next;
                if(temp == NULL){
                    printf("Can't Insert\n");
                    return;
                }
            }    
            ptr->next = temp->next;
            temp->next = ptr;
            printf("Node Inserted\n");
        }
}
int main(){
    int choice = 0;
    while(choice != 5){
        printf("\nMain Menu\n");
        printf("Choose one option\n");
        printf("\n1. Traverse\n2. Insertion at the last\n3. Insertion in the beginning\n4. Insertion in between\n5. Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice) {
            case 1: traverse();break;
            case 2: lastinsert();break;
            case 3: beginsert();break;
            case 4: insertAtPosition();break;
            case 5: printf("Exiting...\n");exit(0);break;
            default:printf("Enter the valid choice\n");
        }
    }
    return 0;
}