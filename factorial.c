//factorial computation up to 200 digits value
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *A = malloc(200*sizeof(int));

    for(int i = 199; i >= 0; i--)
        A[i] = 0;

    A[199] = 1;

    int n;
    scanf("%d", &n);

    int multiply = 1, rest = 0, temp;

    while (n > 0){
        
        for (int i = 199; i >= 0; i--){
            if (A[i] * multiply + rest < 10){
                A[i] = A[i]*multiply + rest;
                rest = 0;
            }     
            
            else{
                temp = A[i];
                A[i] = (A[i] * multiply + rest) % 10;
                rest = (temp * multiply + rest)/10;
            }
                
        }
        multiply++;
        n--;
    }
    
    temp = 0;
    for(int i = 0; i < 200; i++){
        if (A[i] != 0)
            temp = 1;

        if (temp)
            printf("%d", A[i]);
    }
        

    free(A);
    return 0;
}
