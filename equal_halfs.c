#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int tab[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &tab[i]);
    }

    
    for (int i = 0; i < n; i++){
        int sum=0;
        for (int j = 0 ; j < n; j++){
            if (j < i)
                sum += tab[j];
            else if(j > i)
                sum -= tab[j];
        }
        
        if (sum == 0){
            printf("%d", i);
            break;
        }
    }

    return 0;
}