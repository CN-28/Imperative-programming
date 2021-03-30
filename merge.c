/*
t1[n][n] - array filled with natural number, in each row nubers are in ascending order
output linearized and sorted t1 without duplicates
*/


#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    scanf("%d", &n);


    int **t1 = malloc((size_t) n * sizeof(int*));
    for (int i = 0 ; i < n; i++)
        t1[i] = malloc((size_t) n * sizeof(int));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            scanf("%d", &t1[i][j]);
    }


    int *t2 = malloc((size_t) (n * n) * sizeof(int));
    int *temp = calloc((size_t) n, sizeof(int));
    

    int maxi = 0;
    for (int i = 0; i < n; i++){
        if (t1[i][n - 1] > maxi)
            maxi = t1[i][n - 1];
    }
    

    int i = 0, cnt = 0;
    int mini = t1[0][0];
    int index_row = 0;
    while(cnt < n*n){
        for (int j = 0; j < n; j++){
            if (temp[j] < n && t1[j][temp[j]] < mini){
                mini = t1[j][temp[j]];
                index_row = j;
            } 
        }
        temp[index_row]++;
        
        if(i - 1 < 0 || t2[i - 1] != mini){
            t2[i] = mini;
            i++;
        }

        cnt++;
        mini = maxi;
    }

    for (int j = 0; j < i; j++)
        printf("%d ", t2[j]);


    return 0;
}