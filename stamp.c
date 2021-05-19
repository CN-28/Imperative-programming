#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);


    int **T = malloc((size_t) n * sizeof(int *));
    for (int i = 0; i < n; i++){
        T[i] = malloc((size_t) n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &T[i][j]);
    }
    

    int **P = malloc((size_t) k * sizeof(int *));
    for (int i = 0; i < k; i++){
        P[i] = malloc((size_t) l * sizeof(int));
        for (int j = 0; j < l; j++)
            scanf("%d", &P[i][j]);
    }


    int max = 0;
    int sum = 0;
    for (int i = 0; i < n - k; i++){
        for (int j = 0; j < n - l; j++){
            for (int m = 0; m < k; m++){
                for (int o = 0; o < l; o++){
                    if (P[m][o])
                        sum += T[i + m][j + o];
                }
            }
            if (sum > max)
                max = sum;
            sum = 0;
        }
    }
    printf("%d", max);


    for (int i = 0; i < n; i++)
        free(T[i]);
    free(T);


    for (int i = 0; i < k; i++)
        free(P[i]);
    free(P);
    return 0;
}