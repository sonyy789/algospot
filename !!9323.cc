#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n, m, a, b, i, j,inf, dept, dest;
double s, p, y, c, d;
double dist[2][201];
vector<pair<int, pair<double, double>>> adj[201];
int main(){
    inf = 1e9;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%lf%lf%lf",&n,&m,&dept,&dest,&s,&p,&y);
        for(i = 1; i <= n; i++){
            dist[0][i] = dist[1][i] = inf;
            adj[i].clear();
        }
        while(m--){
            scanf("%d%d%lf%lf", &a, &b, &c, &d);
            c /= 100;
            adj[a].push_back({b,{c,d}});
            adj[b].push_back({a,{c,d}});
        }
        priority_queue<pair<double, int>> pq;
        dist[0][dept] = s;
        dist[1][dept] = 0;
        pq.push({0, dept});
        while(!pq.empty()){
            a = pq.top().second;
            pq.pop();
            for(i = 0; i < adj[a].size(); i++){
                bool f1 = false, f2 = false;
                b = adj[a][i].first;
                c = adj[a][i].second.first;
                d = adj[a][i].second.second;
                if(dist[0][b] > dist[0][a]+p*d) dist[0][b] = dist[0][a]+p*d, f1 = true; 
                if(dist[0][b] > dist[1][a]+s+p*d) dist[0][b] = dist[1][a]+s+p*d, f1 = true;
                if(dist[1][b] > min(dist[0][a],dist[1][a])+c*(y+p*d)) dist[1][b] = min(dist[0][a],dist[1][a])+c*(y+p*d), f2= true;
                if(f1) pq.push({-dist[0][b], b});
                if(f2) pq.push({-dist[1][b], b});
            }
        }
        double ans = min(dist[0][dest], dist[1][dest]);
        printf("%.2lf\n", ans);
    }
}