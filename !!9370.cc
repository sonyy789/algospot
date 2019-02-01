#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int z, n, m, t, s, g, h, a, b, d;
int dist[2001];
bool T[2001];
vector<pair<int, int>> adj[2001];

void dijkstra(int start){
    int i;
    dist[start] = 0;
    priority_queue<pair<int, pair<int, bool>>> pq;
    pq.push({0, {start, false}});
    while(!pq.empty()){
        int curr = pq.top().second.first;
        bool prev = pq.top().second.second;
        pq.pop();
        for(i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i].second;
            if(dist[next] >= dist[curr]+adj[curr][i].first){
                dist[next] = dist[curr]+adj[curr][i].first;
                if((curr == g && next == h)||(curr == h && next == g)) prev = true;
                pq.push({-dist[next], {next, prev}});
           }
        }
    }
}
int main(){
    int i, j;
    scanf("%d", &z);
    while(z--){
        scanf("%d%d%d%d%d%d", &n, &m, &t, &s, &g, &h);
        for(i = 1; i <= n; i++){
            dist[0][i] = dist[1][i] = 1e9;
            T[i] = false;
            adj[i].clear();
        }
        while(m--){
            scanf("%d%d%d",&a,&b,&d);
            adj[a].push_back({d,b});
            adj[b].push_back({d,a});
        }
        for(i = 1; i <= t; i++){
            scanf("%d",&a);
            T[a] = true;
        }
        dijkstra(s, 0);
        for(i = 1; i <= n; i++)
            if(T[i]) printf("%d ",i);
        printf("\n");
    }
}