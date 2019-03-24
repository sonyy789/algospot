#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int P[10001], dist[10001];
vector<pair<int, int>> adj[10001];
int dijkstra(int a, int b){
    int i, j;
    priority_queue<pair<int, int>> pq;
    for(i = 1; i <= n; i++) dist[i] = 2e9;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(cost > dist[curr] || curr == n) continue;
        for(i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i].second;
            if((curr==a&&next==b)||(curr==b&&next==a)) continue;
            if(dist[next] > dist[curr]+adj[curr][i].first){
                dist[next] = dist[curr]+adj[curr][i].first;
                if(a==0) P[next] = curr;
                pq.push({-dist[next], next});
            }
        }
    }
    return dist[n];
}
int main(){
    int a, b, c, i, j;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int ans = dijkstra(0,0), res = 0;
    for(i = n; i != P[i]; i = P[i]){
        res = max(res, dijkstra(i, P[i]));
        if(res == 2e9){
            printf("-1");
            return 0;
        }
    }
    printf("%d", res-ans);
}