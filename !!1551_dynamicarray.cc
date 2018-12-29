#include <cstdio>
int main(){
    int n, k, A[21];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d,", &A[i]); 
    while(k--){
        for(int i = 1; i < n; i++)
            A[i-1] = A[i]-A[i-1];
        n--;    
    }
    for(int i = 0; i < n-1; i++) printf("%d,",A[i]);
    printf("%d", A[n-1]);
}