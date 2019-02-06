#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
int dist[20001];
vector<int> adj[20001];
int main(){
    int i;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++) dist[i] = 1e9;
    while(m--){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();
        for(i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i];
            if(dist[next] > dist[curr]+1){
                dist[next] = dist[curr]+1;
                pq.push({-dist[next], next});
            }
        }
    }
    int ans1, ans2, ans3;
    ans1 = ans2 = ans3 = 0;
    for(i = 1; i <= n; i++){
        if(ans2 < dist[i]){
            ans1 = i;
            ans2 = dist[i];
            ans3 = 1;
        }else if(ans2 == dist[i]) ans3++;
    }
    printf("%d %d %d\n", ans1, ans2, ans3);
    
}