#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lld;
int n, m, s, e;
vector<pair<int, int>> adj[1001];
lld inf = 123456789123456789;
lld dist[1001];
int main(){
    int i, j, a, b, c;
    scanf("%d%d",&n, &m);
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({c, b});
    }
    scanf("%d%d", &s, &e);
    for(i = 1; i <= n; i++) dist[i] = inf;    
    queue<pair<lld, int>> q;
    q.push({0, s}); dist[s] = 0;
    while(!q.empty()){
        int curr = q.front().second, cost = q.front().first;
        q.pop();
        if(curr == e) continue;
        for(i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i].second;
            if(dist[next] > dist[curr]+adj[curr][i].first){
                dist[next] = dist[curr]+adj[curr][i].first;
                q.push({-dist[next], next});
            }
        }
    }
    printf("%lld", dist[e]);
}