#include <cstdio>
#define MOD 10007
int n, dp[1001];
int main(){
    dp[1] = 1; dp[2] = 2;
    scanf("%d", &n);
    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    printf("%d\n", dp[n]);
}