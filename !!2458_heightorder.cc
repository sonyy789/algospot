#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int V[2][501];
int n, m;
vector<int> adj[2][501];
int dfs(int curr, int f){
    int i, ret = 1;
    for(i = 0; i < adj[f][curr].size(); i++){
        int next = adj[f][curr][i];
        if(V[f][next]) continue;
        V[f][next] = true;
        ret += dfs(next, f);
    }
    return ret;
}
int main(){
    int i, j, a, b;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++){
       scanf("%d%d", &a, &b);
       adj[0][a].push_back(b);
       adj[1][b].push_back(a);
    }
    int ans = 0;
    for(i = 1; i <= n; i++){
        memset(&V, 0, sizeof(V));
        a = dfs(i,0);
        b = dfs(i,1);
        ans += (a+b)==n+1;
    }
    printf("%d", ans);
}