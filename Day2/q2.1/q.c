#include <stdio.h>

void insert_element(int arr[], int size, int element, int index) {
    // Shift elements to the right to make space for the new element
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[index] = element;

    // Print updated array
    printf("Updated array: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void remove_element(int arr[], int size, int index) {
    // Shift elements to the left to fill the gap left by the removed element
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array
    printf("Updated array: ");
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void linear_search(int arr[], int size, int x) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            printf("Element %d found at index %d\n", x, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array\n", x);
    }
}

void traversal(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[100];
    int size, index, element, choice, position;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

   

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("Menu:\n");
        printf("1. Insert a given element at a specific position\n");
        printf("2. Delete an element from a specific position of the array\n");
        printf("3. Linear search to search for an element\n");
        printf("4. Traversal of the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                if (position < 0 || position > size ) {
                    printf("Invalid position or array full.\n");
                } else {
                    insert_element(arr, size, element, position);
                    size++;  // Increase the size after insertion
                }
                break;

            case 2:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                if (position < 0 || position >= size) {
                    printf("Invalid position.\n");
                } else {
                    remove_element(arr, size, position);
                    size--;  // Decrease the size after deletion
                }
                break;

            case 3:
                printf("Enter the element to search for: ");
                scanf("%d", &element);
                linear_search(arr, size, element);
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

    return 0;
}
