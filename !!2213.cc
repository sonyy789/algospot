#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, b, t_idx;
vector<int> adj[10001];
bool visit[10001];
int W[10001], dp[2][10001], T[10001];
void dfs(int idx){
    int i;
    visit[idx] = true;
    for(i = 0; i < adj[idx].size(); i++){
        int next = adj[idx][i];
        if(!visit[next]){ 
            dfs(next);
            dp[0][idx] += max(dp[0][next],dp[1][next]);
            dp[1][idx] += dp[0][next];
        }
    }
    dp[1][idx] += W[idx];
}
void track(int idx, int flag){
    int i;
    if(flag) T[++t_idx] = idx;
    visit[idx] = true;
    for(i = 0; i < adj[idx].size(); i++){
        int next = adj[idx][i];
        if(visit[next]) continue;
        if(flag) track(next, 0);
        else track(next, dp[0][next]>dp[1][next]?0:1);
    }
}
int main(){
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &W[i]);
    for(i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(i = 1; i <= n; i++) visit[i] = false;
    track(1, dp[0][1]>dp[1][1]?0:1);
    sort(&T[1], &T[t_idx+1]);
    printf("%d\n", max(dp[0][1], dp[1][1]));
    for(i = 1; i <= t_idx; i++)
        printf("%d ", T[i]);
}