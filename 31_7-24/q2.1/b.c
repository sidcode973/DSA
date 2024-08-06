#include <stdio.h>

void deleteElement(int arr[], int size, int index) {
   
    
    // Shift elements to the left to fill the gap
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    size--;


    printf("deletd array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = 2; 
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    deleteElement(arr, size, index);


}