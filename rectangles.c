#include <stdio.h>
#include <stdlib.h>


int max(int a, int b){
    if (a > b)
        return a;
    return b;
}

int min(int a, int b){
    if (a < b)
        return a;
    return b;
}


int main(){
    int n;
    scanf("%d", &n);


    int *A = malloc((size_t) (4 * n) * sizeof(int));
    for(int i = 0; i < 4 * n; i += 4)
        scanf("%d%d%d%d", &A[i], &A[i + 1], &A[i + 2], &A[i + 3]);



    int x_min = A[0], x_max = A[0], y_min = A[1], y_max = A[1];
    for (int i = 0; i < 2 * n; i++){
        if (i % 2 == 0){
            if (A[i] < A[2 * n + i]){
                x_min = min(x_min, A[i]);
                x_max = max(x_max, A[2 * n + i]);
            }
            else{
                x_min = min(x_min, A[2 * n + i]);
                x_max = max(x_max, A[i]);
            }
        }
        else{
            if (A[i] < A[2 * n + i]){
                y_min = min(y_min, A[i]);
                y_max = max(y_max, A[2 * n + i]);
            }
            else{
                y_min = min(y_min, A[2 * n + i]);
                y_max = max(y_max, A[i]);
            }
        }
    }


    int size_Arr = y_max - y_min;
    int **Arr = malloc((size_t) size_Arr * sizeof(int*));
    for (int i = 0; i < size_Arr; i++)
        Arr[i] = calloc((size_t) x_max - x_min, sizeof(int));
    


    for (int i = 0; i < 4 * n; i += 4){
        for (int j = min(A[i + 1], A[i + 3]) - y_min; j < y_max - min(A[i + 1], A[i + 3]); j++){
            for (int k = min(A[i], A[i + 2]) - x_min; k < x_max - min(A[i], A[i + 2]); k++)
                Arr[j][k] = !Arr[j][k];
        }
    }

    int cnt = 0;
    for (int i = 0; i < size_Arr; i++){
        for (int j = 0; j < x_max - x_min; j++){
            if (Arr[i][j])
                cnt++;
        }
            
    }
    printf("%d", cnt);


    free(A);
    for (int i = 0; i < size_Arr; i++)
        free(Arr[i]);
    free(Arr);
    return 0;
}