#include <stdio.h>
#include <stdlib.h>


int main(){
    int N, M;
    scanf("%d%d", &N, &M);


    int cnt = 0, temp;
    for (int i = 0; i < 2 << (N - 1); i++){
        if (i % M != 0){
            for (int j = N - 1; j >= 0; j--){
                temp = i ^ 1UL << j;
                if (temp % M == 0 && temp != 0){
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d", cnt);


    return 0;
}