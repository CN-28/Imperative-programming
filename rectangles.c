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


    
    
    int Arr[201][201] = {0};
    

    for (int i = 0; i < 4 * n; i += 4){
        for (int j = min(A[i + 1] + 100, A[i + 3] + 100); j < max(A[i + 1] + 100, A[i + 3] + 100); j++){
            for (int k = min(A[i] + 100, A[i + 2] + 100); k < max(A[i] + 100, A[i + 2] + 100); k++)
                Arr[j][k] = !Arr[j][k];
                
        }
    }

    int cnt = 0;
    for (int i = 0; i < 201; i++){
        for (int j = 0; j < 201; j++){
            
            if (Arr[i][j])
                cnt++;
        }
    }
    printf("%d", cnt);


    free(A);
    return 0;
}
