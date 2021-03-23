#include <stdio.h>
#include <stdlib.h>


int isPrime(int number){
    if (number == 2 || number == 3)
        return 1;
    else if (number % 2 == 0 || number % 3 == 0 || number < 2)
        return 0;
    
    int i = 5;
    while (i * i <= number){
        if (number % i == 0 || number % (i + 2) == 0)
            return 0;
        
        i += 6;
    }
    return 1;
}


int isOneSquare(int n){
    int number = n;
    int temp = 0;
    while(number != 1 && number != 4){
        while (number != 0){
            temp += (number % 10) * (number % 10);
            number /= 10;
        }
        number = temp;
        temp = 0;
    }
    if (number == 1)
        return 1;
    return 0;
}


int main(){
    int l, u, k, cnt = 0;
    scanf("%d%d%d", &l, &u, &k);

    for (int i = l; i <= u; i++){
        if (isPrime(i) && isOneSquare(i)){
            cnt++;
            if (cnt == k){
                printf("%d", i);
                break;
            }
        }
    }

    if (cnt != k)
        printf("%d", -1);

    return 0;
}