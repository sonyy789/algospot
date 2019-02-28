#include <cstdio>
typedef long long int lld;
int i, j, n, jump;
lld dp[101][101];
int main(){
    scanf("%d", &n);
    dp[1][1] = 1;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++){ 
            scanf("%d", &jump);
            if(jump && dp[i][j]){
                if(i+jump <= n) dp[i+jump][j] += dp[i][j];
                if(j+jump <= n) dp[i][j+jump] += dp[i][j];
            }
        }
    printf("%lld", dp[n][n]);
}