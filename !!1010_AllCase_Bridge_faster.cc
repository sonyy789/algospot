#include <cstdio>
int i, j, k, t, n, m, dp[30][30];
int main(){
    for(i = 1; i < 30; i++) dp[1][i] = i;
    for(i = 2; i < 30; i++)
        for(j = 2; j < 30; j++)
            for(k = i-1; k <= j-1; k++)
                dp[i][j] += dp[i-1][k];
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        printf("%d\n", dp[n][m]);
    }
}