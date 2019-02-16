#include <cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
int n, i, j;
int A[1001], dp[1001];
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &A[i]);
        dp[i] = 1e9;
    }
    dp[1] = 0;
    for(i = 1; i <= n; i++)
        for(j = i+1; j <= i+A[i] && j <= n; j++)
            dp[j] = min(dp[j], dp[i]+1);
    printf("%d", dp[n]==1e9?-1:dp[n]);
}