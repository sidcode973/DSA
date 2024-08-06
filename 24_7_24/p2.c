#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to calculate the sum of prime numbers in an array
int sumOfPrime(int ptr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(ptr[i])) {
            sum += ptr[i];
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Total number: ");
    scanf("%d", &n);

    int *ptr = (int*)calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &ptr[i]);
    }

    int ans = sumOfPrime(ptr, n);
    printf("Final sum: %d\n", ans);

    // Free the allocated memory
    free(ptr);
    return 0;
}
