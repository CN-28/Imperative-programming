#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, m, o;
    scanf("%d%d%d", &n, &m, &o);


    int *Arr = malloc((size_t) (2 * m) * sizeof(int));
    for (int i = 0; i < 2*m; i++)
        scanf("%d", &Arr[i]);
    

    char lower_limit[100];
    char upper_limit[100];
    scanf("%s", lower_limit);
    scanf("%s", upper_limit);
    

    int exit = 1;
    int temp;
    for (int j = 1; j <= m; j++){
        temp = 1;
        for (int i = 0 ; i < m; i++){
            if (Arr[2*i] == j || Arr[2*i + 1] == j){
                temp = 0;
                break;
            }
        }
        if (temp){
            exit = j;
            break;
        }
    }   

    
    int *values = calloc((size_t) m, sizeof(int));
    int *Arr_copy = malloc((size_t) (2 * m) * sizeof(int));
    int x;
    int res=0;
    temp = 0;
    do{
        temp = 0;
        for (int i = 0; i < n; i++){
            if(lower_limit[i] != upper_limit[i])
                temp = 1;
        }

        for (int i = 0; i < 2 * m; i++)
            Arr_copy[i] = Arr[i];
         
        x = 1;
        while(x){
            for (int i = 0; i < m; i++){
                if (Arr[2*i] < 0){
                    values[i] += lower_limit[abs(Arr[2*i]) - 1] - '0';
                    values[i] %= 2;
                    Arr[2*i] = 0;
                }
                    
                if (Arr[2*i + 1] < 0){
                    values[i] += lower_limit[abs(Arr[2*i + 1]) - 1] - '0';
                    values[i] %= 2;
                    Arr[2*i + 1] = 0;
                }

                if (Arr[2*i] > 0){
                    if (Arr[(Arr[2*i] - 1)*2] == 0 && Arr[(Arr[2*i] - 1)*2 + 1] == 0){
                        values[i] += values[Arr[2*i] - 1];
                        values[i] %= 2;
                        Arr[2*i] = 0;   
                    }      
                }

                if(Arr[2*i + 1] > 0)
                    if (Arr[(Arr[2*i + 1] - 1)*2] == 0 && Arr[(Arr[2*i + 1] - 1)*2 + 1] == 0){
                        values[i] += values[Arr[2*i + 1] - 1];
                        values[i] %= 2;
                        Arr[2*i + 1] = 0;
                    }
                        
                if (i == exit - 1 && Arr[2*i] == 0 && Arr[2*i + 1] == 0){
                    x = 0;
                    res += values[exit - 1];
                    break;
                }
            }
        }


        for (int i = 0; i < m; i++)
            values[i] = 0;
    

        for (int i = n - 1; i >= 0; i--){
            if (lower_limit[i] == '1')
                lower_limit[i] = '0';
            else{
                lower_limit[i] = '1';
                break;
            }
        }
        for (int i = 0; i < 2 * m; i++)
            Arr[i] = Arr_copy[i];
    }
    while(temp);
    printf("%d", res);


    free(Arr_copy);
    free(values);
    return 0;
}