#include <cstdio>
int i, j, k, n, m;
int M[1001], adj[201][201];
int main(){
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    for(i = 1; i <= n; i++) adj[i][i] = 1;
    for(i = 1; i <= m; i++) scanf("%d", &M[i]);
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                adj[i][j] |= (adj[i][k]&adj[k][j]);
                
    for(i = 1; i < m; i++)
        if(!adj[M[i]][M[i+1]]) break;
    printf("%s", i==m?"YES":"NO");
}