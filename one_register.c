#include <stdio.h>
#include <stdlib.h>


void solve(int Arr[], char str[], int s, int t, int ind, int len, int isDone[], char result[], int length[]){
    if (ind > length[0])
        return;
    if (s == t){
        int isGreater = 0;
        for (int i = 0; i < 29; i++){
            if (isDone[0] == 0){
                if (str[i] != '0')
                    result[i] = str[i];
            }
            else{
                if (result[i] > str[i]){
                    isGreater = 1;
                    break;
                }
                else if (result[i] < str[i])
                    break;
            }
        }
        int len1 = 0;
        int len2 = 0;
        for (int i = 0; i < 29; i++){
            if (str[i] == '*' || str[i] == '+')
                len1++;
            if (result[i] == '*' || result[i] == '+')
                len2++;
        length[0] = len2;
        }
        if (len1 < len2 || (len1 == len2 && isGreater == 1)){
            length[0] = len1;
            for (int i = 0; i < 29; i++){
                if (str[i] != '0')
                    result[i] = str[i];
            }  
        }
        isDone[0] = 1;
        return;
    }
    if (ind == len)
        return;


    int temp = 0;
    if (s < t){
        Arr[ind] = 0;
        str[ind] = '+';
        s *= 2;
        temp = 1;
        solve(Arr, str, s, t, ind + 1, len, isDone, result, length);
    }
    if (temp){
        s /=2;
        str[ind] = '0';
    }
         
    temp = 0;
    if (s < t){
        Arr[ind] = 1;
        str[ind] = '*';
        s *= s;
        temp = 1;
        solve(Arr, str, s, t, ind + 1, len, isDone, result, length);
    }
    if (temp){
        str[ind] = '0';
        s /= s;
    }
}



int main(){
    int s, t;
    scanf("%d%d", &s, &t);


    int Arr[29] = {-1};
    char str[29] = {'0'};
    int temp = 0;
    int isDone[1] = {0};
    char result[29];
    int length[1];
    length[0] = 30;
    int x = s;
    int cnt = 0;
    if (t % 2 == 1){
        while (x < t && cnt < 29){
            x *= x;
            result[cnt] = '*';
            cnt++;
        }
        if (x == t){
            for (int i = 0; i < cnt; i++)
                printf("%c", result[i]); 
            temp = 1;
        }
    }
    else{
        solve(Arr, str, s, t, 0, 29, isDone, result, length);
        for (int i = 0; i < length[0]; i++){
            if (result[i] == '+' || result[i] == '*'){
                printf("%c", result[i]);
                temp = 1;
            }
            else
                break;
        }
    }
    if (!temp)
        printf("NO");
    return 0;
}