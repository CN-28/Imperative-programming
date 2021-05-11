#include <stdio.h>                                                                                                                       
                                                                                
                                                                                
int main(){                                                                     
    int n;                                                            
    scanf("%d", &n);                                      
    long long int sum = 0;                                                                                                                                                
    int j = 1;
    for (int i = 1; i <= n; i+=2){                                              
        j = i;
        while (j <= n){
            sum += i;
            j *= 2;  
        }                                                                                
    }                                                                           

    printf("%lld", sum);                                                                                                                                              
    return 0;                                                                   
}                                                                               