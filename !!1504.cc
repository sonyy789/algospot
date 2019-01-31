#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, a, b, c, inf = 1e8;
int start[3];
vector<pair<int, int>> adj[801];
int dist[3][801];
void dijkstra(int s, int idx){
    int i, j;
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    for(i = 1; i <= n; i++) dist[idx][i] = inf;
    dist[idx][s] = 0;
    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();
        for(i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i].second;
            if(dist[idx][next] > dist[idx][curr]+adj[curr][i].first){
                dist[idx][next] = dist[idx][curr]+adj[curr][i].first;
                pq.push({-dist[idx][next], next});
            }
        }
    }
}
int main(){
    int i, j; 
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    start[0] = 1;
    scanf("%d%d", &start[1], &start[2]);
    for(i = 0; i < 3; i++)
        dijkstra(start[i],i);
    a = b = 0;
    a = dist[0][start[1]]+dist[1][start[2]]+dist[2][n];
    b = dist[0][start[2]]+dist[2][start[1]]+dist[1][n];
    a = min(a,b);
    printf("%d", a < inf?a:-1);
}