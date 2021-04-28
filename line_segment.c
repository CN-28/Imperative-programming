#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int **Arr = malloc((size_t) n * sizeof(int *));
    for (int i = 0; i < n; i++){
        Arr[i] = malloc((size_t) n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &Arr[i][j]);
    }
    int all_max = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int max4 = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int l = 0; l < k; l++){
                max1 += Arr[(i + l) % n][(j + l) % n];
                max2 += Arr[(i + l) % n][j];
                max3 += Arr[i][(j + l) % n];
                max4 += Arr[(i + l) % n][(n + j - l) % n];
            }

            if (max1 > all_max)
                all_max = max1;
            if (max2 > all_max)
                all_max = max2;
            if (max3 > all_max)
                all_max = max3;
            if (max4 > all_max)
                all_max = max4;
            max1 = max2 = max3 = max4 = 0;
        }
    }
    printf("%d", all_max);
    
    for (int i = 0; i < n; i++)
        free(Arr[i]);
    free(Arr);
    return 0;
}