/*
given n, create a spiral in T[n][n], values from 1 to n*n 
*/
#include <stdio.h>
#include <stdlib.h>


int main(){

    int n;
    scanf("%d", &n);

    int **A = malloc((size_t) n * sizeof(int *));
    for (int i = 0; i < n; i++)
        A[i] = malloc((size_t) n * sizeof(int));

    int temp = n - 1;
    int num = 1;
    int i = 0, j = 0;
    while (temp > 0){
        for (int k = 0; k < temp; k++){
            A[i][j] = num;
            num++;
            j++;
        }
        
        for (int k = 0; k < temp; k++){
            A[i][j] = num;
            num++;
            i++;
        }
        for (int k = 0; k < temp; k++){
            A[i][j] = num;
            num++;
            j--;
        }
        for (int k = 0; k < temp; k++){
            A[i][j] = num;
            num++;
            i--;
        }
        i++;
        j++;
        temp -= 2;
    }
    if (n % 2 == 1)
        A[n/2][n/2] = num;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }


    for (int i = 0 ; i < n; i++)
        free(A[i]);
    free(A);
    return 0;
}