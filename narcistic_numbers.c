#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* converter(char numbers[], int m, int base, int tobase){
    int result = 0;
    int power = 1;
    for (int i = m - 1; i >= 0; i--){
        switch(numbers[i]){
            case 'A':
                result += power*10;
                break;
            case 'B':
                result += power*11;
                break;
            case 'C':
                result += power*12;
                break;
            case 'D':
                result += power*13;
                break;
            case 'E':
                result += power*14;
                break;
            case 'F':
                result += power*15;
                break;
            default:
                result += power*(numbers[i] - '0');
        }
        power *= base;
    }
    int number = result;

    char *res = malloc(sizeof(char));
    int n = 1;

    int rest;
    while(number != 0){
        res = realloc(res, sizeof(char)*n);
        rest = number % tobase;
        char char_val[1];
        switch(rest){
            case 10:
                res[n - 1] = 'A';
                break;
            case 11:
                res[n - 1] = 'B';
                break;
            case 12:
                res[n - 1] = 'C';
                break;
            case 13:
                res[n - 1] = 'D';
                break;
            case 14:
                res[n - 1] = 'E';
                break;
            case 15:
                res[n - 1] = 'F';
                break;
            default:
                sprintf(char_val, "%d", rest);
                res[n - 1] = char_val[0];
        }

        number /= tobase;
        n++;
    }
    n--;
    char temp;
    for (int i = 0; i < n/2; i++){
        temp = res[i];
        res[i] = res[n - 1 - i];
        res[n - 1 - i] = temp; 
    }

    return res;
}


int narcistic(char numbers[], int n, int m){
    int result = 0;
    for (int i = 0; i < m; i++){
        int temp = 1;
        for(int j = 0; j < m; j++)
            switch(numbers[i]){
                case 'A':
                    temp *= 10;
                    break;
                case 'B':
                    temp *= 11;
                    break;
                case 'C':
                    temp *= 12;
                    break;
                case 'D':
                    temp *= 13;
                    break;
                case 'E':
                    temp *= 14;
                    break;
                case 'F':
                    temp *= 15;
                    break;
                default:
                    temp *= (numbers[i] - '0');
            }
            
            
        result += temp;  
    }
    if (result == n)
        return 1;
    else
        return 0;
    
}


int main(){
    int m, b;
    scanf("%d%d", &m, &b);

    char min[m];
    for (int i = 0; i < m; i++){
        min[i] = '0';
    }
    min[0] = '1';
    

    //ustalanie prawego krańca przedziału
    long long int max = 0;
    int power = 1;
    for (int i = 0; i < m; i++){
        max += (b - 1)*power;
        power *= b;
    }

    char* mini = converter(min, m, b, 10);
    int minim = atoi(mini);

    int bool_var = 0;
    for (int i = minim; i <= max; i++){
        int temp = i;
        int dl = 0;
        while (temp != 0){
            dl++;
            temp /= 10;
        }
        char num[dl]; 
        sprintf(num, "%d", i);
        
        if (narcistic(converter(num, dl, 10, b) ,i ,m ) == 1){
            char *x = converter(num, dl, 10, b);
            printf("%s ", x);
            bool_var = 1;
        }
    }
    if (bool_var == 0){
        printf("NO");
    }
    return 0;
}