/*
Array NxN filled with 0's and 1's, find the maximum field of the rectangle filled only with 0's
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int **A = malloc((size_t) n * sizeof(int*));
    for (int i = 0 ; i < n; i++)
        A[i] = malloc((size_t) n * sizeof(int));


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    }

    int temp = 0;
    int max = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (A[i][j] == 1)
                continue;
            for (int k = 1; k <= n - i; k++){
                for (int l = 1; l <= n - j; l++){
                    if (k * l > max){
                        temp = 0;
                        for (int m = i; m < i + k; m++){
                            for (int o = j; o < j + l; o++){
                                if (A[m][o] != 0){
                                    temp = 1;
                                    break;
                                }
                                    
                            }
                            if (temp)
                                break;
                                
                        }
                        if (!temp && k * l > max)
                            max = k * l;
                    }
                }
            }
            
        }
    }
    printf("%d", max);


    for (int i = 0 ; i < n; i++)
        free(A[i]);
    free(A);

    return 0;
}