#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, v;
vector<int> adj[1001];
bool visited[1001];
void dfs(int curr){
    visited[curr] = true;
    printf("%d ", curr);
    for(int i = 0; i < adj[curr].size(); i++){
        int next = adj[curr][i];
        if(visited[next]) continue;
        dfs(next);
    }
}
void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        printf("%d ", curr);
        for(int next : adj[curr]){
            if(visited[next]) continue;
            q.push(next); visited[next] = true;
        }
    }
}
int main(){
    int i, j, a, b;
    scanf("%d%d%d", &n, &m, &v);
    while(m--){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    dfs(v); printf("\n");
    memset(&visited, 0, sizeof(visited));
    bfs(v);
}