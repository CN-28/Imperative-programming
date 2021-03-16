#include <stdio.h>
#include <stdlib.h>

#define N 100

void solve(int weights[], int isUsed[], int index, int n, int sum, int w){
    int bool_var = 0;
    for(int i = 0; i < n; i++){
        if (isUsed[i] == 0){
            bool_var = 1;
        }
    }
    
    if (sum == w){
        printf("YES");
        exit(0);
    }
    if (bool_var == 0)
        return;
    

    for (int i = index; i < n; i++){
        if (isUsed[i] == 0){
            isUsed[i] = 1;
            solve(weights, isUsed, i + 1, n, sum + weights[i], w);
            isUsed[i] = 0;
        }
        
            
        if (isUsed[i] == 0){
            isUsed[i] = 1;
            solve(weights, isUsed, i + 1, n, sum - weights[i], w);
            isUsed[i] = 0;
        }
    }
}


int main(){
    int n;
    long w;
    int weights[N];
    int isUsed[N];
    scanf("%d%ld", &n, &w);
    int sum_all = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &weights[i]);
        sum_all += weights[i];
    }
    for (int i = 0; i < n; i++){
        isUsed[i] = 0;
    }
    if(sum_all >= w)
        solve(weights, isUsed, 0, n, 0, w);
    printf("NO");

    return 0;
}
