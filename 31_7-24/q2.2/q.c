#include <stdio.h>

// Function to find the number of non-zero elements
int countNonZeroElements(int matrix[][10], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangular(int matrix[][10], int size) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j >= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to display elements just above and below the main diagonal
void displayAboveBelowDiagonal(int matrix[][10], int size) {
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i - 1 || j == i + 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    int matrix[10][10];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int nonZeroCount = countNonZeroElements(matrix, size);
    printf("Number of non-zero elements: %d\n", nonZeroCount);

    displayUpperTriangular(matrix, size);
    displayAboveBelowDiagonal(matrix, size);

    return 0;
}
