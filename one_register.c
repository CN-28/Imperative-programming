#include <stdio.h>
#include <stdlib.h>


void solve(char str[], long long int s, int t, int ind, int len, int isDone[], char result[], int length[]){
    if (ind > length[0])
        return;
    if (s == t){
        int isGreater = 0;
        for (int i = 0; i < 30; i++){
            if (isDone[0] == 0){
                result[i] = '0';
                if (str[i] == '+' || str[i] == '*')
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
        for (int i = 0; i < 30; i++){
            if (str[i] == '*' || str[i] == '+')
                len1++;
            if (result[i] == '*' || result[i] == '+')
                len2++;
        }
        length[0] = len2;
        if (len1 < len2 || (len1 == len2 && isGreater == 1)){
            length[0] = len1;
            for (int i = 0; i < 30; i++){
                result[i] = '0';
                if (str[i] == '*' || str[i] == '+')
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
        str[ind] = '+';
        s *= 2;
        temp = 1;
        solve(str, s, t, ind + 1, len, isDone, result, length);
    }
    if (temp){
        s /=2;
        str[ind] = '0';
    }
         
    temp = 0;
    if (s < t){
        str[ind] = '*';
        s *= s;
        temp = 1;
        solve(str, s, t, ind + 1, len, isDone, result, length);
    }
    if (temp){
        str[ind] = '0';
        s /= s;
    }
}



int main(){
    int s, t;
    scanf("%d%d", &s, &t);


    char str[30] = {'0'};
    int temp = 0;
    int isDone[1] = {0};
    char result[30] = {'0'};
    int length[1];
    length[0] = 30;
    long long int x = s;
    int cnt = 0;
    
    if (t == 0 && s != 0){
        printf("-");
        return 0;
    }
    if (s == 0 && t == 0 || s == t)
        return 0;
    if (s == 0 && t != 0){
        printf("NO");
        return 0;
    }
    if (t == 1 && s != 0){
        printf("/");
        return 0;
    }
    //podpunkt 1
    if (t % 2 == 1){
        while (x < t && cnt < 30){
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
    //podpunkt 2
    else if (t % s != 0){
        x = 2;
        if (x == t){
            printf("/+");
            temp = 1;
        }
        else{
            solve(str, x, t, 0, 30, isDone, result, length);
            for (int i = 0; i < length[0] ; i ++){
                if (result[i] == '+' || result[i] == '*'){
                    temp = 1;
                    if (i == 0)
                        printf("/+");
                    printf("%c", result[i]);
                }
                else
                    break;
            }
        }
    }
    //brute force
    else{
        int tempLength = 0;
        solve(str, x, t, 0, 30, isDone, result, length);
        for (int i = 0; i < 30; i++)
            str[i] = '0';
        tempLength = length[0];
        int tempRes[30];
        int firstDone = 0;
        if (isDone[0] != 0){
            firstDone = 1;
            for (int i = 0; i < 30; i++)
                tempRes[i] = result[i];
        }
        solve(str, 1, t, 0, 30, isDone, result, length);
        if (length[0] + 1 < tempLength || (firstDone == 0 && isDone[0] != 0)){
            for (int i = 0; i < length[0] ; i ++){
                if (result[i] == '+' || result[i] == '*'){
                    temp = 1;
                    if (i == 0)
                        printf("/");
                    printf("%c", result[i]);
                }
                else
                    break;
            }
        }
        else{
            for (int i = 0; i < tempLength ; i ++){
                if (tempRes[i] == '+' || tempRes[i] == '*'){
                    temp = 1;
                    printf("%c", tempRes[i]);
                }
                else
                    break; 
            }
        }    
    }


    if (!temp)
        printf("NO");
    return 0;
}