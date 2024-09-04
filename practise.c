#include<stdio.h>


int main(){
    int n , index , position , element  ,choice ;
    int arr[100] ;
     printf("enter the no of element:");
     scanf("%d" , &size);
    
    for(int i=0 ; i< n ;i++ ){
         printf("enter the element of the array");
     scanf("%d" ,&arr[i] );
    }
    while(1){
        printf("Menu:\n");
        printf("1. Insert a given element at a specific position\n");
        printf("2. Delete an element from a specific position of the array\n");
        printf("3. Linear search to search for an element\n");
        printf("4. Traversal of the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case:1
            printf("enter the element to insert");
            scanf("%d" ,&element);
            printf("Enter the position to insert at: ");
            scanf("%d", &position);
            inser(arr , n , element , position);
            size++;
            break;

            case:2
            printf("eneter the position to delete");
            scanf("%d" ,&choice);
            delete(arr, n , position);
            size--;
            break;

            case:3
            printf("enter the element to search for");
            scanf("%d" , &element);
            search(arr , n,choice) ;
            break;
             case 4:
                traversal(arr, size);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}