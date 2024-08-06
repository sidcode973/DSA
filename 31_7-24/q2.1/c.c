#include<stdio.h>

int linearSearch(int arr[] , int size , int element){
    for (int i=0 ; i<size  ; i++){
        if(arr[i] == element){
            return i ; 
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 2; 
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   int ans = linearSearch(arr, size,element);
   printf("index of element:");
   printf("%d" , ans);


}