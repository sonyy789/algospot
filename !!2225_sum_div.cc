#include <cstdio>
int main(){
    int i, j, n, k, dp[201], mod = 1e9;
    scanf("%d%d", &n, &k);
    for(i = 0; i <= n; i++)
        dp[i] = 1;
    for(i = 1; i < k; i++)
        for(j = 1; j <= n; j++)
            dp[j] = (dp[j]+dp[j-1])%mod;
    printf("%d\n", dp[n]);
}