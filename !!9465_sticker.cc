#include <cstdio>
int t, n, dp[2][100003];
int max(int a, int b){return a>b?a:b;}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < 2; i++)
            for(int j = 1; j <= n; j++) scanf("%d", &dp[i][j]);
        dp[0][0] = dp[1][0] = 0;
        for(int j = 0; j < n; j++){
            dp[1][j+2] += max(dp[0][j], dp[0][j+1]);
            dp[0][j+2] += max(dp[1][j], dp[1][j+1]);
        }
        printf("%d\n", max(max(dp[0][n-1],dp[0][n]), max(dp[1][n-1], dp[1][n])));
    }
}