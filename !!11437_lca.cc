#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int R[50001][16], D[50001];
vector<int> adj[50001];
bool V[50001];
int lca(int a, int b){
    if(D[a] > D[b]) swap(a,b);
    int depth_diff = D[b]-D[a];
    while(depth_diff){
        int n = depth_diff&(-depth_diff);
        depth_diff -= n;
        b = R[b][(int)log2(n)];
    }
    while(1){
        if(a == b) return a;
        a = R[a][0];
        b = R[b][0];
    }
}
int main(){
    int a, b, i, j, n, m;
    scanf("%d", &n);
    for(i = 1; i < n; i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    V[1] = true; D[1] = 0;
    while(!q.empty()){
        int curr = q.front();
        int depth = D[curr];
        q.pop();
        for(i = 1; (1<<i) <= depth; i++)
            R[curr][i] = R[R[curr][i-1]][i-1];
        for(i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i];
            if(V[next]) continue;
            V[next] = true;
            R[next][0] = curr; D[next] = depth+1;
            q.push(next);
        }
    }
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a,b));
    }
}