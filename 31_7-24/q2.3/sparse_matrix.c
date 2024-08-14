#include<stdio.h>
#include <stdlib.h>
int main(){
    int rows,columns;
    int non_zero_elements=0;
    int x=1;
    printf("enter the number rows and columns of the sparse matrix:\n");
    scanf("%d%d",&rows,&columns);
    int arr[rows][columns];
    printf("enter the elements of the matrix:\n ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0){
                non_zero_elements++;
            }
        }    
    }
    int sparse_matrix[non_zero_elements][3];
    sparse_matrix[0][0]=rows;
    sparse_matrix[0][1]=columns;
    sparse_matrix[0][2]=non_zero_elements;

for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            
            if(arr[i][j]!=0){
                sparse_matrix[x][0]=i;
                sparse_matrix[x][1]=j;
                sparse_matrix[x][2]=arr[i][j];    
                x++;            
            }
        }    
    }

for(int i=0;i<=non_zero_elements;i++){
        for(int j=0;j<3;j+=3){
            
            printf("%d  ",sparse_matrix[i][j]);    
            printf("%d  ",sparse_matrix[i][j+1]); 
            printf("%d  ",sparse_matrix[i][j+2]);  
            printf("\n");
                       
            }
        }
        return 0;    
    }