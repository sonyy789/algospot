#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int W[16][16], dp[65536][16];
bool V[65536][16];
int main(){
    int i,j,n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) 
            scanf("%d", &W[i][j]);
    int last = (1<<n);
    for(int i = 1; i < last; i++)
        for(int j = 0; j < n; j++) dp[i][j] = 1e9;
    dp[1][0] = 0;
    queue<pair<int ,int>> q;
    q.push({1,0});
    int nStat;
    while(!q.empty()){
        int stat = q.front().first;
        int curr = q.front().second;
        q.pop();
        for(int i = 0, visit= 1; i < n; i++, visit<<=1){
            if(W[curr][i] == 0 || stat&visit) continue;
            nStat = stat|visit;
            dp[nStat][i] = min(dp[nStat][i], dp[stat][curr]+W[curr][i]);
            if(V[nStat][i] == false) q.push({nStat, i});
            V[nStat][i] = true;
        }
    }
    int ans = 2e9;
    for(int i = 1; i < n; i++){
        if(!W[i][0]) continue;
        ans = min(ans, dp[last-1][i]+W[i][0]);
    }
    printf("%d", ans);
}