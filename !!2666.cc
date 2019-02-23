#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, a, b, l, i, j, k, inf = 2e9;
int A[21];
int dp[21][21][21];
int main(){
    scanf("%d%d%d%d", &n, &a, &b, &l);
    for(k = 0;  k <= l; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++) dp[k][i][j] = inf;
    for(i = 1; i <= l; i++) 
        scanf("%d", &A[i]);
    dp[0][min(a,b)][max(a,b)] = 0;
    for(k = 1; k <= l; k++)
        for(i = 1; i < n; i++)
            for(j = i+1; j <= n; j++){
                if(dp[k-1][i][j] == inf) continue;
                a = min(j,A[k]), b = max(j, A[k]);
                dp[k][a][b] = min(dp[k][a][b], dp[k-1][i][j]+abs(A[k]-i));
                a = min(i,A[k]), b = max(i, A[k]);
                dp[k][a][b] = min(dp[k][a][b], dp[k-1][i][j]+abs(A[k]-j));
            }
    int ans = inf;
    for(i = 1; i < n; i++)
        for(j = i+1; j <= n; j++) 
            ans = min(ans, dp[l][i][j]);
    printf("%d", ans);
}