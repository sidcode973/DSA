#include<stdio.h>
void  insert_element(int arr[] ,int size ,int element,int index){
    int size1 = size+1;
    int newarr[size1];
    for(int i=0;i<index;i++){
        newarr[i]=arr[i];
    }
    newarr[index]=element;
    for(int i=index ;i<size;i++){
        newarr[i+1]=arr[i];
    }
    for(int i=0;i<size1;i++){
        printf("%d" , newarr[i]);
    }
    
}
void remove_element(int arr[] , int n,int index){
  int i=0;  
for(i=index;i<n;i++){
    arr[i]=arr[i+1];
    }
    n--;
}
void linear_search(int arr[] ,int n,int x){
    int i=0;
    for(i=0;i<n;i++){
    if(arr[i]==x){
            printf("element found %d" , x);
    }
        }
}
void traversal(int arr[],int n){
   for(int i=0;i<n;i++){
    printf("%d " , arr[i]);
    }
    printf("\n");
}
int main(){
    int size , index , element , choice , position;
    int arr[100];
    printf("enter thenumber of elements ");
    scanf("%d", &size);
    printf("enter the elements of array");
    for(int i =0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    while(1){
        printf("\nMenu:\n");
        printf("1. Insert a given element at a specific position\n");
        printf("2. Delete an element from a specific position of the array\n");
        printf("3. Linear search to search an element\n");
        printf("4. Traversal of the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            printf("enter the element to insert");
            scanf("%d",&element);
            printf("enter the position to insert");
            scanf("%d" , &position);
            printf("updated array");
            insert_element(arr , size , element , position);
            break;
            
            case 2:

            printf("enter the position to delete from ");
            scanf("%d" , &position);
            remove_element(arr , size ,  position);
            printf("updated array");
            traversal(arr , size);
            break;
            
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                linear_search(arr, size, element);
                
                break;
                
            case 4:
                printf("Array elements: ");
                traversal(arr, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
            } 
        }
        
        
        return 0;

    }