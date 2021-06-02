#include <stdio.h>
#include <stdlib.h>



int main(){
    int t, n;
    scanf("%d", &t);
    double **Arr = malloc((size_t) t * sizeof(double *));
    int *lengths = malloc((size_t) t * sizeof(int));
    for (int i = 0; i < t; i++){
        scanf("%d", &n);
        lengths[i] = n;
        Arr[i] = malloc((size_t) (4*n) * sizeof(double));
        for (int j = 0; j < n; j++)
            scanf("%lf %lf", &Arr[i][4*j], &Arr[i][4*j + 1]);
    }


    for (int i = 0; i < t; i++){
        for (int j = 0; j < lengths[i]; j++){
            Arr[i][4*j + 2] = (Arr[i][4*j] + Arr[i][(4*j + 4) % (4 * lengths[i])])/2;
            Arr[i][4*j + 3] = (Arr[i][4*j + 1] + Arr[i][(4*j + 5) % (4 * lengths[i])])/2;
        }
    }


    double P_x, P_y, Q_x, Q_y, A_x, A_y, B_x, B_y;
    int res, ans = 0, temp = 0;
    for (int i = 0; i < t; i++){
        ans = 0;
        for (int k = 0; k < lengths[i]; k++){
            res = 0;
            P_x = Arr[i][2*k];
            P_y = Arr[i][2*k + 1];
            Q_x = Arr[i][2*k + 2*lengths[i]];
            Q_y = Arr[i][2*k + 2*lengths[i] + 1];
            for (int m = 1; m < lengths[i]; m++){
                temp = 0;
                A_x = Arr[i][(2*k - 2*m + 4*lengths[i]) % (4 * lengths[i])];
                A_y = Arr[i][(2*k - 2*m + 1 + 4*lengths[i]) % (4 * lengths[i])];
                B_x = Arr[i][(2*k + 2*m) % (4 * lengths[i])];
                B_y = Arr[i][(2*k + 2*m + 1) % (4 * lengths[i])];
                if (((P_x - A_x)*(P_x - A_x) + (P_y - A_y)*(P_y - A_y)) == ((P_x - B_x)*(P_x - B_x) + (P_y - B_y)*(P_y - B_y))){
                    if (((Q_x - A_x)*(Q_x - A_x) + (Q_y - A_y)*(Q_y - A_y)) == ((Q_x - B_x)*(Q_x - B_x) + (Q_y - B_y)*(Q_y - B_y))){
                        temp = 1;
                        res++;
                    }    
                }
                if (!temp)
                    break;
            }
            if (res == lengths[i] - 1)
                ans++;
        }
        printf("%d\n", ans);
    }
   


    for (int i = 0; i < t; i++)
        free(Arr[i]);
    free(Arr);
    free(lengths);
    return 0;
}