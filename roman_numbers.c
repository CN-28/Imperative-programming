#include <stdio.h>
#include <stdlib.h>


int letterToInt(char letter){
    switch( letter ){
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
    }  
}


int main(){
    char A[15];
    char B[15];
    scanf("%s%s", A, B);


    int sum = 0;
    int index = 1;
    while (A[index] != '\0'){
        if (letterToInt(A[index - 1]) < letterToInt(A[index]))
            sum -= letterToInt(A[index - 1]);
        else
            sum += letterToInt(A[index - 1]);
        index++;
    }
    sum += letterToInt(A[index - 1]);


    index = 1;
    while (B[index] != '\0'){
        if (letterToInt(B[index - 1]) < letterToInt(B[index]))
            sum -= letterToInt(B[index - 1]);
        else
            sum += letterToInt(B[index - 1]);
        index++;
    }
    sum += letterToInt(B[index - 1]);


    const char *M[] = {"", "M", "MM", "MMM"};
    const char *C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char *X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char *I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char res[15];

    
   
    int temp_index = 0;
    index = 0;
    int cnt = 0;
    while (M[sum / 1000][temp_index] != '\0'){
        if (sum / 1000 > 0){
            res[index] = M[sum / 1000][temp_index];
            temp_index++;
            index++;
        }
        cnt++;
    }
    

    temp_index = 0;
    while (C[(sum / 100) % 10][temp_index] != '\0'){
        if ((sum / 100) % 10 > 0){
            res[index] = C[(sum / 100) % 10][temp_index];
            temp_index++;
            index++;
        }
        cnt++;
    }
    

    temp_index = 0;
    while (X[(sum / 10) % 10][temp_index] != '\0'){
        if((sum / 10) % 10 > 0){
            res[index] = X[(sum / 10) % 10][temp_index];
            temp_index++;
            index++;
        }
        cnt++;
    }
    


    temp_index = 0;
    while (I[sum % 10][temp_index] != '\0'){
        if(sum % 10 > 0){
            res[index] = I[sum % 10][temp_index];
            temp_index++;
            index++;
        }
        cnt++;
    }
    
    

    for (int i = 0; i < cnt; i++)
        printf("%c", res[i]); 


    return 0;
}