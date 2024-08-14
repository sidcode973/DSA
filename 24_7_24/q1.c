#include<stdio.h>

void compare(int* num1 , int* num2){
    if(*num1 > *num2){
        printf("%d is greater than %d\n", num1,num2);
    }
    else if(*num1 < *num2){
        printf("%d is smaller than %d\n", *num1, *num2);
    }
    else{
        printf("%d is equal to %d\n", *num1, *num2);
    }
}

int main() {
    int num1 , num2 ;
    printf("enter first number: ");
    scanf("%d" , &num1) ;

    printf("enter second number: ");
    scanf("%d" , &num2);

    compare(&num1 , &num2);
}