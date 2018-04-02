#include <cstdio>
int n, i, j, dp[1001];
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++) scanf("%d", &dp[i]);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= i && i+j<=n; j++)
            dp[i+j] = dp[i+j]>(dp[i]+dp[j])?dp[i+j]:(dp[i]+dp[j]);
    printf("%d\n", dp[n]);
}