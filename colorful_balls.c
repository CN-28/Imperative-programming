#include <stdio.h>
#include <stdlib.h>


int max(int a, int b, int c){
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    if (c >= a && c >= b)
        return c;
}


int main(){
    int n;
    scanf("%d", &n);
    int **Arr = malloc((size_t) 3 * sizeof(int *));
    for (int i = 0; i < 3; i++){
        Arr[i] = malloc((size_t) n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &Arr[i][j]);
    }
    int res = 0;
    int *A = malloc((size_t) n * sizeof(int));
    int taken[3] = {0};
    for (int i = 0; i < n; i++){
        if (Arr[0][i] >= Arr[1][i] && Arr[0][i] >= Arr[2][i]){
            A[i] = 0;
            taken[0] = 1;
        }
        else if (Arr[1][i] >= Arr[0][i] && Arr[1][i] >= Arr[2][i]){
            A[i] = 1;
            taken[1] = 1;
        }
        else if (Arr[2][i] >= Arr[0][i] && Arr[2][i] >= Arr[1][i]){
            A[i] = 2;
            taken[2] = 1;
        }    
    }


    int cnt = 0;
    for (int i = 0; i < 3; i++){
        if (!taken[i])
            cnt++;
    }

    int mini = 1999999999;
    int tempTaken[3] = {0};
    for (int i = 0; i < 3; i++)
        tempTaken[i] = taken[i];
    int temp = 0;
    if (cnt == 1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 3; j++){
                if (j == A[i])
                    continue;
                tempTaken[j] = 1;
                for (int k = 0; k < n; k++){
                    for (int l = 0; l < 3; l++){
                        if (k == i && l != j)
                            res += Arr[l][k];  
                        else if (k != i && l != A[k])
                            res += Arr[l][k];         
                    }
                }
                for (int i = 0; i < 3; i++){
                    if (tempTaken[i] == 0)
                        temp += 1;
                    tempTaken[i] = taken[i];
                }
                if (res < mini && temp == 0)
                    mini = res;
                res = 0;
                temp = 0;
            }
        }
    }

    
    for (int i = 0; i < 3; i++)
        tempTaken[i] = taken[i];
    temp = 0;
    if (cnt == 2){
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < 3; j++){
                if (j == A[i])
                    continue;
                tempTaken[j] = 1;
                for (int k = i + 1; k < n; k++){
                    for (int l = 0; l < 3; l++){
                        if (l == A[k] || j == l)
                            continue;
                        tempTaken[l] = 1;
                        for (int m = 0; m < n; m++){
                            for (int o = 0; o < 3; o++){
                                if (m == i && o != j)
                                    res += Arr[o][m];
                                else if (m == k && o != l)
                                    res += Arr[o][m]; 
                                else if (m != i && m != k && o != A[m])
                                    res += Arr[o][m];
                            }
                        }
                        for (int i = 0; i < 3; i++){
                            if (tempTaken[i] == 0)
                                temp += 1;
                            tempTaken[i] = taken[i];
                        }
                        if (res < mini && temp == 0)
                            mini = res;
                        res = 0;
                        temp = 0;
                    }
                }
            }
        }
    }

    if (cnt == 0){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 3; j++){
                if (j != A[i])
                    res += Arr[j][i];
            }
        }
        mini = res;
    }
    cnt = 0;
    if (n == 1){
        for (int i = 0; i < 3; i++){
            if (Arr[i][0] == 0)
                cnt++;
        }
        if (cnt == 2)
            printf("%d", 0);
        else
            printf("-1");
    }
    else if (n == 2){
        temp = 0;
        int ind = -1;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < n; j++){
                if (Arr[i][j] == 0)
                    cnt++;
            }
            if (cnt == 2){
                ind = i;
                temp = 1;
                break;
            }
            cnt = 0;
        }
        if (!temp)
            printf("-1");
        else{
            int maxi1 = 0;
            int maxi2 = 0;
            res = 0;
            for (int j = 0; j < 3; j++){
                if (Arr[j][0] > Arr[maxi1][0])
                    maxi1 = j;
            }
            for (int j = 0; j < 3; j++){
                if (Arr[j][1] > Arr[maxi2][1])
                    maxi2 = j;
            }
            if (Arr[maxi1][0] >= Arr[maxi2][1] && maxi1 != maxi2){
                printf("%d", Arr[maxi1][1] + Arr[maxi2][0]);
            }
            else if (maxi1 == maxi2 && Arr[maxi1][0] >= Arr[maxi2][1]){
                res += Arr[maxi2][1];
                for (int i = 0; i < 3; i++){
                    if (i != maxi2 && i != ind)
                        res += Arr[i][0];
                }
            }
            else if (maxi1 == maxi2){
                res += Arr[maxi2][0];
                for (int i = 0; i < 3; i++){
                    if (i != maxi2 && i != ind)
                        res += Arr[i][1];
                }
            }
            printf("%d", res);
        }
    }
    else
        printf("%d", mini);


    free(A);
    free(Arr);
    return 0;
}