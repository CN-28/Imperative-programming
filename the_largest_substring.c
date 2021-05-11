#include <stdio.h>
#include <string.h>


int main(){
    char string[50];
    scanf("%s", string);
    int len = strlen(string);
    int Arr[50] = {0};

    char max;
    for (int i = len - 1; i >= 0; i--){
        if (string[i] >= max){
            Arr[i] = 1;
            max = string[i];
        }
    }


    for (int i = 0; i < len; i++){
        if (Arr[i] == 1)
            printf("%c", string[i]);
    }



    return 0;
}