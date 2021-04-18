#include <stdio.h>
#include <math.h>

int main(){
    int a, b, suma = 1, ile=0;
    int tab[10], k = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++){
        suma = 1;
        for (int j = 2; j <= sqrt(i); j++ ){
            if(i % j == 0){
                suma += j;
                suma += i/j;
            }
        }
        if (suma == i && suma != 1){
            tab[k] = i;
            k++;
            ile++;
        }
    }
    printf("%d\n", ile);
    for (int l = 0; l < k; l++){
        printf("%d ", tab[l]);
    }
    return 0;
}