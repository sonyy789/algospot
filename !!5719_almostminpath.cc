#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge{
    int u, v, p;
};
int n, m;
vector<Edge> edge;
int D[501];
void bellman(int s){
    int i, j;
    for(i = 0; i < n; i++) D[i] = 1e9;
    D[s] = 0;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < m; j++){
            if(edge[j].p < 0) continue;
            D[edge[j].v] = min(D[edge[j].v], D[edge[j].u]+edge[j].p);
        }
}
void del_edge(int d){
    int i, j;
    D[d] = -D[d];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(-(D[edge[j].u]+edge[j].p) == D[edge[j].v]){
                edge[j].p = -edge[j].p;
                D[edge[j].u] = -D[edge[j].u];
            }
        }
    }
}
int main(){
    int i, s, d;
    while(1){
        scanf("%d%d", &n, &m);
        if((n|m) == 0) break;
        for(i = 0; i < n; i++) D[i] = 1e9;
        edge = vector<Edge>(m);
        scanf("%d%d", &s, &d);
        for(i = 0; i < m; i++)
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].p);
        bellman(s);
        del_edge(d);
        bellman(s);
        printf("%d\n", D[d]!=1e9?D[d]:-1);
    }
}