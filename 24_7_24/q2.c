#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPrime(int num){
    if(num <= 1) { return false;} 
    if(num == 2 || num == 3){ return true;} ;

    for(int i =2 ; i*i <= num ;i++){
        if(num % i == 0){
            return false;
        } 
    }
    return true ;
}
int primeSum(int ptr[] , int n) {
    int sum= 0 ;
    for(int i= 0 ; i< n ; i++){
    if(isPrime(ptr[i])){
        sum += ptr[i] ;
    }
    }
    return sum ;
}

int main(){
    int n ;
    printf("Total Numbers: ") ;
    scanf("%d" , &n);

    int *ptr = (int*)calloc(n, sizeof(int));
    for(int i =0 ; i<n ; i++){
        printf("Enter Element:") ;
        scanf("%d" , &ptr[i]) ;    }

        int ans= primeSum(ptr , n) ;
        printf("The sum of prime is %d\n" ,ans) ;

        free(ptr) ;
        return 0 ;
}