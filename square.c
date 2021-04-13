/*
There is T[n][n] filled with natural numbers, find squares MxM contained in array T,
such that sum of elements on the perimeter of the square is equal to k.
M is an odd number and greater than 1. Print number of found squares and for each found square print the coordinates of the middle point of this square.
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    int **A = malloc((size_t) n * sizeof(int *));
    for (int i = 0; i < n; i++)
        A[i] = malloc((size_t) n * sizeof(int));


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    }

    int *res = malloc((size_t) (n*n) * sizeof(int));
    int index = 0;

    int cnt = 0, sum = 0, temp = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int l = 3; l <= n - max(i, j); l += 2){
                sum = 0;
                for (int m = 0; m < l; m++){
                    sum += A[i][j + m];
                    sum += A[i + m][j];
                    sum += A[i + l - 1][j + m];
                    sum += A[i + m][j + l - 1];
                }
                sum -= A[i][j];
                sum -= A[i + l - 1][j];
                sum -= A[i + l - 1][j + l - 1];
                sum -= A[i][j + l - 1];
                if (sum == k){
                    temp = 0;
                    for (int o = 0; o < index; o += 2){
                        if (i + l/2 == res[o] && j + l/2 == res[o + 1]){
                            temp = 1;
                            break;
                        } 

                    }

                    if (!temp){
                        res[index] = i + l/2;
                        index++;
                        res[index] = j + l/2;
                        index++;
                    }
                    cnt++;
                }
                    
            }

        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < index; i++)
        if (i % 2 == 1)
            printf("%d\n", res[i]);
        else
            printf("%d ", res[i]);


    free(res);
    for (int i = 0 ; i < n; i++)
        free(A[i]);
    free(A);
    return 0;
}