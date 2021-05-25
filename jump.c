#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int n;
    scanf("%d", &n);
    int *Arr = malloc((size_t) 2*n * sizeof(int));

    int max_pawn = 0;
    int max_ind = 0;
    int min_ind =(int) INFINITY;
    for (int i = 0; i < 2*n; i++){
        scanf("%d", &Arr[i]);
        if (i % 2 == 1 && Arr[i] > max_pawn)
            max_pawn = Arr[i];
        else if (i % 2 == 0){
            if (Arr[i] > max_ind)
                max_ind = Arr[i];
            if (Arr[i] < min_ind)
                min_ind = Arr[i];
        }  
    }
    int res = log10(max_pawn);
    if (res == 0)
        res++;

    
    int len = (max_ind - min_ind) + 2*res*10;
    int *temp = calloc((size_t) len, sizeof(int));
    int mid = res*10;
    

    for (int i = 0; i < n; i++)
        temp[res*10 + Arr[2*i] - min_ind] = Arr[2*i + 1];
    

    int x = 0;
    int y = 0;
    while (!x){
        x = 1;
        for (int i = len - 3; i >= 2; i--){
            
            while (temp[i] >= 1){
                y = 1;
                if (temp[i - 1] != 0){
                    x = 0;
                    y = 0;
                    temp[i - 1]--;
                    temp[i]--;
                    temp[i + 1]++;
                }
                else if (temp[i + 1] != 0){
                    x = 0;
                    y = 0;
                    temp[i]--;
                    temp[i + 1]--;
                    temp[i + 2]++;
                }
                else if (temp[i] > 1){
                    x = 0;
                    y = 0;
                    temp[i]--;
                    temp[i - 1]++;
                    temp[i - 2]++;
                } 
                if (y == 1)
                    break;
            }    
        }
        
    }
    
    
    for (int i = 0; i < len; i++){
        if(temp[i] == 1)
            printf("%d ", -(mid - i - min_ind));
    }


    free(Arr);
    free(temp);
    return 0;
}