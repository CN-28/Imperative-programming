#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    int *Arr = malloc((size_t) (2 * m) * sizeof(int));
    for (int i = 0; i < 2 * m; i++)
        scanf("%d", &Arr[i]);

    int *Set = malloc((size_t) n * sizeof(int));
    int index = 0;
    int temp = 1;
    for (int i = 0 ; i < 2 * m; i++){
        temp = 1;
        for (int j = 0 ; j < index; j++){
            if (Set[j] == Arr[i]){
                temp = 0;
                break;
            }
        }
        if (temp){
            Set[index] = Arr[i];
            index++;
        }            
    }
    

    int cnt = 0;
    int cnt_tri = 0;
    for (int i = 0; i < n - 2; i ++){
        for (int j = i + 1; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                cnt = 0;
                for (int l = 0; l < 2 * m; l+=2){
                    if ((Set[i] == Arr[l] && Set[j] == Arr[l + 1]) || (Set[j] == Arr[l] && Set[i] == Arr[l + 1]))
                        cnt++;
                    else if ((Set[i] == Arr[l] && Set[k] == Arr[l + 1]) || (Set[k] == Arr[l] && Set[i] == Arr[l + 1]))
                        cnt++;
                    else if ((Set[j] == Arr[l] && Set[k] == Arr[l + 1]) || (Set[k] == Arr[l] && Set[j] == Arr[l + 1]))
                        cnt++;
                }
                if (cnt == 3 || cnt == 0)
                    cnt_tri++;
            }
            
        }
    }
    printf("%d", cnt_tri);


    free(Arr);
    free(Set);
    return 0;
}