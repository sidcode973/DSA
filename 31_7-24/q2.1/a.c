#include <stdio.h>
void insertElement(int arr[], int size, int element, int index) {
     // Shift elements to the right to make space for the new element
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    size++;

    printf("inerted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    } 
}
int main() {
    int arr[100] = {1, 2, 3, 4, 5}; // Initial array with extra space
    int size = 5;
    int element = 10; 
    int index = 2; 

    insertElement(arr, size, element, index);

}