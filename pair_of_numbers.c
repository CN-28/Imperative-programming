#include <stdio.h>
#include <stdlib.h>

int compare_function(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}


int main(){

    int n, k;
    scanf("%d%d", &n, &k);
    int *A = (int*) calloc((size_t) n, sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
   
  
    qsort(A, (size_t) n, sizeof(int), compare_function);

    int j, m, left, mid, right, temp;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        j = i - 1;
        left = 0;
        temp = 0;
        while (left <= j){
            mid = (left + j)/2;
            if (A[mid] < A[i] && A[mid] < A[i] - k)
                left = mid + 1;
            else if(A[mid] >= A[i] - k && A[mid] != A[i]){
                cnt++;
                temp = 1;
                break;
            }
            else if(A[mid] >= A[i])
                j = mid - 1;
            
            
        }

        if(temp == 0){
            m = i + 1;
            right = n - 1;
            while (m <= right){
                mid = (m + right)/2;
                if (A[mid] > A[i] && A[mid] > A[i] + k)
                    right = mid - 1;
                else if (A[mid] <= A[i] + k && A[mid] != A[i]){
                    cnt++;
                    break;
                }
                else if(A[mid] <= A[i])
                    m = mid + 1;
            
            }
        
        }
    }
    
    
    printf("%d", cnt);
    free(A);

    return 0;
}