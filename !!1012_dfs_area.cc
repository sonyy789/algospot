#include <cstdio>
int t, n, m, k, a, b;
bool visit[51][51];
void dfs(int y, int x){
    visit[y][x] = false;
    if(visit[y-1][x] && y-1 >= 0) dfs(y-1, x);
    if(visit[y][x-1] && x-1 >= 0) dfs(y, x-1);
    if(visit[y+1][x] && y+1 < n) dfs(y+1, x);
    if(visit[y][x+1] && x+1 < m) dfs(y, x+1);
    return;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &m, &n, &k);
        while(k--){
            scanf("%d %d", &a, &b);
            visit[b][a] = true;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(visit[i][j]) {dfs(i, j); ans++;}
        printf("%d\n", ans);
    }
}