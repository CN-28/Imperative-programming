#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int ten_powers(int power){
    int num = 1;
    for (int i = 0; i < power; i++)
        num *= 10;
    return num;
}


int main(){
    long long int S;
    scanf("%lld", &S);
    int len = log10(S) + 1;
    

    long long int sum = 1;
    for (int j = 0; j < len - 1; j++){
        sum *= 10;
        sum += 1; 
    }
    
    
    int *number = calloc((size_t) len, sizeof(int));
    for (int i = 0 ; i < len; i++){
        while (S - sum >= 0){
            S -= sum;
            number[i]++;
            if (number[i] > 9){
                printf("-1");
                free(number);
                return 0;
            }
                
        }
        sum /= 10;
    }
    

    int k = 0;
    if (number[0] == 0)
        k = 1; 
    for (k; k < len; k++)
        printf("%d", number[k]);
    
    
    free(number);
    return 0;
}