/*
F[n][n] - array filled with numbers from {0, 1}, r - distance between two elements in array 
r(F[i][j], F[i'][j']) = max(|i - i'|, |j - j'|), compute array W[n][n] filled with sum of all elements F[i'][j']
distanced at most r from F[i][j]
*/

#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, r;
    scanf("%d%d", &n, &r);
    
    int **F = malloc((size_t) n * sizeof(int*));
    for (int i = 0; i < n; i++)
        F[i] = malloc((size_t) n * sizeof(int));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            scanf("%d", &F[i][j]);
    }


    int **W = malloc((size_t) n * sizeof(int*));
    for (int i = 0; i < n; i++){
        W[i] = malloc((size_t) n * sizeof(int));
        for (int j = 0; j < n; j++)
            W[i][j] = 0;
    }
    
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = -r; k <= r; k++){
                for (int l = -r; l <= r; l++){
                    if (i + k < n && i + k >= 0 && j + l < n && j + l >= 0 && F[i + k][j + l])
                            W[i][j]++;

                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        
        for (int j = 0; j < n; j++)
            printf("%d ", W[i][j]);

        printf("\n");
    }  
    
    free(F);
    free(W);
    return 0;
}