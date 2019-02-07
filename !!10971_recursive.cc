#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1024][11], adj[10][10];
int n;
void solve(int idx, int stat, int cost){
   if(dp[stat][idx] && dp[stat][idx] <= cost) return;
   dp[stat][idx] = cost;
   for(int i = 0, a = 1; i < n; i++, a<<=1){
       if(!adj[idx][i] || (stat&a)) continue;
       solve(i, stat|a, cost+adj[idx][i]);
   } 
}

int main(){
    int i, j, a, last;
    scanf("%d", &n);
    last = (1<<n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]);
    solve(0, 1, 0);
    int ans = 1e9;
    for(i = 1; i < n; i++){
        if(!adj[i][0] || !dp[last-1][i]) continue;
        ans = min(ans, dp[last-1][i]+adj[i][0]);
    }
    printf("%d", ans);
}