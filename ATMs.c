#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int isGreater(int A[], int B[]){
    for (int i = 0; i < 31; i++){
        if (A[i] > B[i])
            return 1;
        else if (B[i] > A[i])
            return 0;
    }
    return 0;
}


int isEqual(int A[], int B[]){
    for (int i = 0; i < 31; i++){
        if (A[i] > B[i])
            return 0;
        else if (B[i] > A[i])
            return 0;
        if (i == 30)
            return 1;
    }
}


int find(int Arr[], int B[], int tempArr[], int opt){
    int temp = 1;
    int rest;
    int cnt = 0;
    int cnt_taken = opt;
    while (temp){
        rest = 0;
        for (int i = 30; i >= 0; i--){
            B[i] = B[i] * 2 + rest;
            rest = 0;
            if (B[i] >= 10){
                B[i] %= 10;
                rest = 1;
            } 
        }

        if (isGreater(B, Arr))
            temp = 0;
        else if (isEqual(Arr, B))
            temp = 0;    
        
        
        cnt++;
        if (cnt % 2 == opt && temp == 1){
            cnt_taken = cnt;
            for (int i = 0; i < 31; i++)
                tempArr[i] = B[i];
        }
    }
    return cnt_taken;
}


void powerArr(int B[], int n){
    for (int i = 0; i < n; i++){
        int rest = 0;
        for (int i = 30; i >= 0; i--){
            B[i] = B[i] * 2 + rest;
            rest = 0;
            if (B[i] >= 10){
                B[i] %= 10;
                rest = 1;
            } 
        }
    }
}


void addArr(int A[], int B[]){
    int rest = 0;
    for (int i = 30; i >= 0 ; i--){
        A[i] += B[i] + rest;
        rest = 0;
        if (A[i] >= 10){
            rest = A[i]/10;
            A[i] %= 10;
        }
    }
}


void subtArr(int A[], int B[]){
    for (int i = 30; i >= 0; i--){
        A[i] -= B[i];
        if (A[i] < 0){
            A[i] += 10;
            if (i - 1 >= 0)
                A[i - 1]--;
        }
    }
}


int main(){
    char input[31];
    scanf("%s", input);
    int Arr[31] = {0};
    int taken[100] = {0};
    int len = strlen(input);
    int done = 0;
    for (int i = 0; i < len; i++)
        Arr[30 - (len - i - 1)] = input[i] - '0';
    
    
    int B[31] = {0};
    B[30] = 1;
    int check[31];
    int tempArr[31] = {0};
    tempArr[30] = 1;
    int ArrCopy[31];
    int sum[31] = {0};
    int aux[31] = {0};
    aux[30] = 1;
    if (isEqual(Arr, B)){
        done = 1;
        printf("%d\n", 0);
    }
    int x = find(Arr, B, tempArr, 0);
    for (int i = 0; i < 31; i++)
        ArrCopy[i] = tempArr[i];
  
    
    taken[x] = 1;

    for (int i = x - 1; i >= 0; i--){
        for (int j = 0; j < 31; j++)
            B[j] = 0;
        B[30] = 1;
        powerArr(B, i);
        for (int j = 0; j < 31; j++){
            check[j] = tempArr[j];
            sum[j] = 0;
        }
        if (i % 2 == 1){
            subtArr(check, B);
            for (int j = i - 1; j >= 0; j--){
                if (j % 2 == 0){
                    for (int k = 0; k < 31; k++)
                        aux[k] = 0;
                    aux[30] = 1;
                    powerArr(aux, j);
                    addArr(sum, aux);
                }  
            }
            addArr(check, sum);
            if (isGreater(check, Arr) || isEqual(check, Arr)){
                subtArr(tempArr, B);
                taken[i] = 1;
            }
                
        }
        else{
            addArr(check, B);
            for (int j = i - 1; j >= 0; j--){
                if (j % 2 == 1){
                    for (int k = 0; k < 31; k++)
                        aux[k] = 0;
                    aux[30] = 1;
                    powerArr(aux, j);
                    addArr(sum, aux);
                }
            }
            subtArr(check, sum);
            if (isGreater(Arr, check) || isEqual(Arr, check)){
                addArr(tempArr, B);
                taken[i] = 1;
            }
                
        }
        if (isEqual(Arr, tempArr)){
            done = 1;
            for (int i = 0; i < 100; i++){
                if (taken[i])
                    printf("%d ", i);
            }
            printf("\n");
            break;
        }
    }
    
    int max[31] = {0};
    max[30] = 1;
    powerArr(max, 99);
    for (int i = 0; i < 100; i++)
        taken[i] = 0;
    for (int i = 0; i < 31; i++)
        tempArr[i] = ArrCopy[i];
    powerArr(tempArr, 2);
    x += 2;
    int end = 0;
    if (isGreater(tempArr, max) && done == 0){
        done = 1;
        end = 1;
    }
        
    if (!done){
        taken[x] = 1;
        for (int i = x - 1; i >= 0; i--){
            for (int j = 0; j < 31; j++)
                B[j] = 0;
            B[30] = 1;
            powerArr(B, i);
            for (int j = 0; j < 31; j++){
                check[j] = tempArr[j];
                sum[j] = 0;
            }
            if (i % 2 == 1){
                subtArr(check, B);
                for (int j = i - 1; j >= 0; j--){
                    if (j % 2 == 0){
                        for (int k = 0; k < 31; k++)
                            aux[k] = 0;
                        aux[30] = 1;
                        powerArr(aux, j);
                        addArr(sum, aux);
                    }  
                }
                addArr(check, sum);
                if (isGreater(check, Arr) || isEqual(check, Arr)){
                    subtArr(tempArr, B);
                    taken[i] = 1;
                }
                    
            }
            else{
                addArr(check, B);
                for (int j = i - 1; j >= 0; j--){
                    if (j % 2 == 1){
                        for (int k = 0; k < 31; k++)
                            aux[k] = 0;
                        aux[30] = 1;
                        powerArr(aux, j);
                        addArr(sum, aux);
                    }
                }
                subtArr(check, sum);
                if (isGreater(Arr, check) || isEqual(Arr, check)){
                    addArr(tempArr, B);
                    taken[i] = 1;
                }
                    
            }
            if (isEqual(Arr, tempArr)){
                done = 1;
                for (int i = 0; i < 100; i++){
                    if (taken[i])
                        printf("%d ", i);
                }
                printf("\n");
                break;
            }
        }
    }
    if (!done || end)
        printf("NO\n");





    done = 0;
    for (int i = 0; i < 100; i++)
        taken[i] = 0;

    for (int i = 0; i < 31; i++){
        B[i] = 0;
        tempArr[i] = 0;
    }
    tempArr[30] = 2;
    B[30] = 1;
    
    x = find(Arr, B, tempArr, 1);
    for (int i = 0; i < 31; i++)
        ArrCopy[i] = tempArr[i];
    
    
    taken[x] = 1;
    for (int i = x - 1; i >= 0; i--){
        for (int j = 0; j < 31; j++)
            B[j] = 0;
        B[30] = 1;
        powerArr(B, i);
        for (int j = 0; j < 31; j++){
            check[j] = tempArr[j];
            sum[j] = 0;
        }
        if (i % 2 == 0){
            subtArr(check, B);
            for (int j = i - 1; j >= 0; j--){
                if (j % 2 == 1){
                    for (int k = 0; k < 31; k++)
                        aux[k] = 0;
                    aux[30] = 1;
                    powerArr(aux, j);
                    addArr(sum, aux);
                }  
            }
            addArr(check, sum);
            if (isGreater(check, Arr) || isEqual(check, Arr)){
                subtArr(tempArr, B);
                taken[i] = 1;
            }
                
        }
        else{
            addArr(check, B);
            for (int j = i - 1; j >= 0; j--){
                if (j % 2 == 0){
                    for (int k = 0; k < 31; k++)
                        aux[k] = 0;
                    aux[30] = 1;
                    powerArr(aux, j);
                    addArr(sum, aux);
                }
            }
            subtArr(check, sum);
            if (isGreater(Arr, check) || isEqual(Arr, check)){
                addArr(tempArr, B);
                taken[i] = 1;
            }
                
        }
        if (isEqual(Arr, tempArr)){
            done = 1;
            for (int i = 0; i < 100; i++){
                if (taken[i])
                    printf("%d ", i);
            }
            printf("\n");
            break;
        }
    }

    


    for (int i = 0; i < 100; i++)
        taken[i] = 0;
    powerArr(ArrCopy, 2);
    x += 2;
    end = 0;
    if (isGreater(ArrCopy, max) && done == 0){
        done = 1;
        end = 1;
    }
        
    if (!done){
        
        
        taken[x] = 1;
        for (int i = x - 1; i >= 0; i--){
            for (int j = 0; j < 31; j++)
                B[j] = 0;
            B[30] = 1;
            powerArr(B, i);
            for (int j = 0; j < 31; j++){
                check[j] = ArrCopy[j];
                sum[j] = 0;
            }
            if (i % 2 == 0){
                subtArr(check, B);
                for (int j = i - 1; j >= 0; j--){
                    if (j % 2 == 1){
                        for (int k = 0; k < 31; k++)
                            aux[k] = 0;
                        aux[30] = 1;
                        powerArr(aux, j);
                        addArr(sum, aux);
                    }  
                }
                addArr(check, sum);
                if (isGreater(check, Arr) || isEqual(check, Arr)){
                    subtArr(ArrCopy, B);
                    taken[i] = 1;
                }
                    
            }
            else{
                addArr(check, B);
                for (int j = i - 1; j >= 0; j--){
                    if (j % 2 == 0){
                        for (int k = 0; k < 31; k++)
                            aux[k] = 0;
                        aux[30] = 1;
                        powerArr(aux, j);
                        addArr(sum, aux);
                    }
                }
                subtArr(check, sum);
                if (isGreater(Arr, check) || isEqual(Arr, check)){
                    addArr(ArrCopy, B);
                    taken[i] = 1;
                } 
            }
            if (isEqual(Arr, ArrCopy)){
                done = 1;
                for (int i = 0; i < 100; i++){
                    if (taken[i])
                        printf("%d ", i);
                }
                printf("\n");
                break;
            }
        }
    }
    if (!done || end)
        printf("NO");
    

    return 0;
}