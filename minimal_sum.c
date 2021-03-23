#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int main(){

    int n, k;
    scanf("%d %d", &n, &k);
    int *Arr = malloc(sizeof(int)*(size_t) n);
    for (int i = 0; i < n; i++)
        scanf("%d", &Arr[i]);
    
    qsort(Arr, (size_t) n, sizeof(int), cmpfunc);
    int i = n - 1;
    int sum = 0;
    while (k > 0){
        Arr[i] /= 2;
        if (i - 1 >= 0 && Arr[i] <= Arr[i - 1]){
            sum += Arr[i];
            i--;
        }
        k--;
        if (i == 0 && k == 0){
            sum += Arr[i];
        }
    }
    for (int j = i; j >= 0; j--)
        sum += Arr[j];
    printf("%d", sum);

    return 0;
}