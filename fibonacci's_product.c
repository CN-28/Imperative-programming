#include <stdio.h>

int main(){
    long int f1=0, f2=1;
    long int n;
    scanf("%ld", &n);

    while(f1*f2 < n){
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    if (f1 * f2 == n){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}