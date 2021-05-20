#include <stdio.h>
#include <stdlib.h>


void solve(int Arr[], int T[], int res[], int N, int cnt, int X, int G, int count[]){
    if (cnt == N){
        X = 0;
        for (int i = 0; i < N; i++){
            if (Arr[i] == 1 && T[i] != -1)
                X |= T[i];
        }
        if (X == G)
            for (int i = 0; i < N; i++){
                if (Arr[i] == 1 && T[i] != -1)
                    count[i] += 1;
            }
        return;
    }


    Arr[cnt] = 0;
    solve(Arr, T, res, N, cnt + 1, X, G, count);
    Arr[cnt] = 1;
    solve(Arr, T, res, N, cnt + 1, X, G, count);
}


int main(){
    int N, G;
    scanf("%d%d", &N, &G);
    int *T = malloc((size_t) N * sizeof(int));
    int cnt = 0;
    int x = 0;
    for (int i = 0; i < N; i++){
        scanf("%d", &T[i]);
        if (T[i] < G)
            cnt++;
        else if (T[i] == G)
            x++;
    }
    

    int *temp = malloc((size_t) cnt * sizeof(int));
    int j = 0;
    for (int i = 0; i < N; i++){
        if (T[i] < G){
            temp[j] = T[i];
            j += 1;
        }
    }

    
    int *count = malloc((size_t) cnt * sizeof(int));
    int *Arr = malloc((size_t) cnt * sizeof(int));
    int res[1];
    res[0] = 0;
    

    int is = 0;
    int maxi;
    while (is == 0){
        solve(Arr, temp, res, cnt, 0, 0, G, count);
        maxi = 0;
        for (int i = 1; i < cnt; i++){
            if (count[i] > count[maxi])
                maxi = i;
        }
        if (count[maxi] == 0)
            is = 1;
        else{
            res[0]++;
            temp[maxi] = -1;
        }
        for (int i = 0; i < cnt; i++)
            count[i] = 0;       
    }
    printf("%d", res[0] + x);
    


    free(T);
    free(Arr);
    free(temp);
    return 0;
}