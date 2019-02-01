#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, x, a, b, c, ans;
int dist[2][1001];
int adj[1001][1001];
int main(){
    int i, j;
    scanf("%d%d%d",&n,&m,&x);
    for(i = 1; i <= m; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a][b] = c;
    }
    for(i = 1; i <= n; i++)
        dist[0][i] = dist[1][i] = 1e9;
    priority_queue<pair<int, int>> pq;
    for(i = 0; i < 2; i++){
        dist[i][x] = 0;
        pq.push({0,x});
        while(!pq.empty()){
            int curr = pq.top().second;
            pq.pop();
            for(j = 1; j <= n; j++){
                c = (i&1)?adj[j][curr]:adj[curr][j];
                if(c && dist[i][j] > dist[i][curr]+c){
                    dist[i][j] = dist[i][curr]+c;
                    pq.push({-dist[i][j], j});
                }
            }
        }
    }
    for(i = 1; i <= n; i++)
        ans = max(ans, dist[0][i]+dist[1][i]);
    printf("%d", ans);
}