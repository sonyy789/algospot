#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lld;
struct Point{ 
    lld c;
    int idx, k; 
    bool operator<(const Point &P) const {
        return c<P.c;
    }
};
int n, m, k;
lld inf = 123456789123456789;
vector<pair<int, int>> adj[10001];
lld dp[10001][21];
int main(){
    int i, j, a, b, c;
    scanf("%d%d%d", &n, &m, &k);
    while(m--){
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(i = 1; i <= n; i++)
        for(j = 0; j <= k; j++) dp[i][j] = inf;
    priority_queue<Point> q;
    q.push({0, 1, k});
    dp[1][k] = 0;
    while(!q.empty()){
        int curr = q.top().idx;
        int kk = q.top().k;
        lld cost = -q.top().c;
        q.pop();
        if(cost > dp[curr][kk] || curr == n) continue;
        for(i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i].first;
            if(kk && dp[curr][kk] < dp[next][kk-1]){
                dp[next][kk-1] = dp[curr][kk];
                q.push({-dp[next][kk-1], next, kk-1});
            }
            if(dp[curr][kk]+adj[curr][i].second < dp[next][kk]){
                dp[next][kk] = dp[curr][kk]+adj[curr][i].second;
                q.push({-dp[next][kk], next, kk});
            }
        }
    }
    lld ans = inf;
    for(j = 0; j <= k; j++)
        ans = min(ans, dp[n][j]);
    printf("%lld", ans);
}