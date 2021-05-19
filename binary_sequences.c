#include <stdio.h>
#include <stdlib.h>

void solve(int Arr[], int n, int index, int cnt[], int k){
    if (index == n){
        cnt[0]++;
        if (cnt[0] == k){
            for (int i = 0; i < n; i++)
                printf("%d", Arr[i]);
            exit(0);
        }
        return;
    }
    


    Arr[index] = 0;
    solve(Arr, n, index + 1, cnt, k);
    if (index == 0 || (index - 1 >= 0 && Arr[index - 1] != 1)){
        Arr[index] = 1;
        solve(Arr, n, index + 1, cnt, k);
    }
    
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int *Arr = malloc((size_t) n * sizeof(int));
    int cnt[1] = {0};
    solve(Arr, n, 0, cnt, k);
    printf("%d", -1);

    free(Arr);
    return 0;
}