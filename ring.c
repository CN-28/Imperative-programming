#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char str[50];
    scanf("%s", str);
    int len = strlen(str);
    int Arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int lenArr = 15;


    char *res = malloc((size_t) len * sizeof(char));
    for(int i = 0; i < len; i++)
        res[i] = str[i];
    int temp;
    int isGreater;
    for (int o = 0; o < len; o++){
        for (int i = 0; i < lenArr; i++){
            if (Arr[i] >= len)
                break;


            temp = Arr[i];
            isGreater = 0;
            for (int k = 0; k < len; k++){
                if (str[(o + temp) % len] < res[k]){
                    isGreater = 1;
                    break;
                }  
                else if (str[(o + temp) % len] > res[k])
                    break;
                temp += Arr[i];
            }


            if (isGreater){
                temp = Arr[i];
                for (int k = 0; k < len; k++){
                    res[k] = str[(o + temp) % len];
                    temp += Arr[i];
                }
            }
        }
    }
    printf("%s", res);


    free(res);
    return 0;
}