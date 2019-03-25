#include <cstdio>
int n;
int A[20][20], dp[3][20][20];
int main(){
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    dp[0][1][2] = 1;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++){
            if(!A[i][j+1]) dp[0][i][j+1] += (dp[0][i][j]+dp[2][i][j]);
            if(!A[i+1][j]) dp[1][i+1][j] += (dp[1][i][j]+dp[2][i][j]);
            if((A[i][j+1]|A[i+1][j]|A[i+1][j+1])==0) 
                dp[2][i+1][j+1] += dp[0][i][j]+dp[1][i][j]+dp[2][i][j]; 
        }
    printf("%d", dp[0][n][n]+dp[1][n][n]+dp[2][n][n]);
}