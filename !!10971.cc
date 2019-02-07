#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1024][11], adj[10][10];
int n, i, j, a, last;
int main(){
    scanf("%d", &n);
    last = (1<<n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]);
    for(i = 0; i < last; i++)
        for(j = 0; j < n; j++) dp[i][j] = 1e9;
    dp[1][0] = 0;
    for(int stat = 1; stat < last; stat+=2)
        for(i = 0; i < n; i++){
            if(dp[stat][i] == 1e9) continue;
            for(j = 0, a = 1; j < n; j++, a<<=1){
                if(!adj[i][j] || (stat&a)) continue;
                dp[stat|a][j] = min(dp[stat|a][j], dp[stat][i]+adj[i][j]);
            }
        }
    int ans = 1e9;
    for(i = 1; i < n; i++){
        if(!adj[i][0]) continue;
        ans = min(ans, dp[last-1][i]+adj[i][0]);
    }
    printf("%d", ans);
}