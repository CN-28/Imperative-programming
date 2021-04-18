#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    long int n;
    scanf("%ld", &n);
    static long int tab[100000000];

    tab[0] = 0;
    tab[1] = 0;
    for (long int i = 2; i < 100000000; i++){
        tab[i] = 1;
    }
    

    for(long int i = 2; i <= sqrt(n); i++){
        if (tab[i]){
            long int k = 2;
            while (k*i <= n){
                tab[k*i] = 0;
                k++;
            }
        }
    }

    for (long int i = 0; i < n; i++){
        if (tab[i] == 1){
            long int temp = i;
            long int reszta = temp % 10;
            temp = temp/10;
            while (temp != 0){
                if(reszta >= temp % 10){
                    reszta = temp % 10;
                    temp = temp/10;
                }
                else{
                    break;
                }
            }
            if (temp == 0){
                printf("%ld\n", i);
            } 
            
        }
    }
    return 0;
}