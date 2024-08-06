#include<stdio.h>
void traverseArray(int arr[] , int size){
printf("traversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}



int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]); 
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    traverseArray(arr, size);
}