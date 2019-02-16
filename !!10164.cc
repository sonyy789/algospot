#include <cstdio>
using namespace std;
int n, m, k, i, j, y, x, ans;
int dp[20][20];
int main(){
    dp[1][1] = 1;
    for(i = 1; i <= 15; i++) dp[i][1] = dp[1][i] = 1;
    for(i = 2; i <= 15; i++)
        for(j = 2; j <= 15; j++)
            dp[i][j] += (dp[i-1][j]+dp[i][j-1]);
    scanf("%d%d%d", &n, &m, &k);
    ans = dp[n][m];
    if(k){
        x = (k-1)%m+1;
        y = (k-1)/m+1;
        ans = dp[y][x]*dp[n-y+1][m-x+1];
    }
    printf("%d", ans);
}