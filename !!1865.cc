#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge{
    int s, e, t;
};
int z, n, m, w, s, e, t, i, j;
int dist[501];
int main(){
    scanf("%d", &z);
    while(z--){
        scanf("%d%d%d", &n, &m, &w);
        for(i = 1; i <= n; i++) dist[i] = 1e9;
        int size = 2*m+w;
        vector<Edge> edge(size+1);
        for(i = 1; i <= (m<<1); i+=2){
            scanf("%d%d%d", &edge[i].s, &edge[i].e, &edge[i].t);
            edge[i+1].s = edge[i].e, edge[i+1].e = edge[i].s, edge[i+1].t = edge[i].t;
        }
        for(i; i <= size; i++){
            scanf("%d%d%d", &edge[i].s, &edge[i].e, &edge[i].t);
            edge[i].t = -edge[i].t;
        }
        dist[1] = 0;
        for(i = 1; i < n; i++)
            for(j = 1; j <= size; j++)
                dist[edge[j].e] = min(dist[edge[j].e], dist[edge[j].s]+edge[j].t);
        bool flag = false;
        for(j = 1; j <= size; j++)
            if(dist[edge[j].e] > dist[edge[j].s]+edge[j].t) flag = true;
        printf("%s\n", flag?"YES":"NO");
    }
}