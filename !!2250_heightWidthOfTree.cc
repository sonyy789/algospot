#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int D[10001][2], adj[10001][2];
int idx;
bool IN[10001];
void dfs(int node, int depth){
    if(adj[node][0] != -1) dfs(adj[node][0], depth+1); ++idx;
    D[depth][0] = -max(-D[depth][0], -idx), D[depth][1] = max(D[depth][1], idx);
    if(adj[node][1] != -1) dfs(adj[node][1], depth+1);
}
int main(){
    int n, a, b, c, i, root;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a][0] = b, adj[a][1] = c;
        IN[b] = b > 0 ? true:IN[b];
        IN[c] = c > 0 ? true:IN[c];
        D[i][0] = 1e9;
    }
    for(i = 1; i <= n; i++)
        if(IN[i] == false) root = i;
    dfs(root, 1);
    int level, inv=0, d = 0;
    while(D[++d][1]){
        int tmp = D[d][1]-D[d][0]+1;
        if(inv < tmp){
            inv = tmp;
            level = d;
        }
    }
    printf("%d %d", level, inv);
}