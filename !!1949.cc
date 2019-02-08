#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int W[10001];
vector<int> adj[10001];
int solve(int idx, bool use, int prev){
    int ret, i, j, a, b;
    ret = 0;
    for(i = 0; i < adj[idx].size(); i++){
        int next =  adj[idx][i];
        if(next == prev) continue;
        a = b = 0;
        a = solve(next, 0, idx);
        if(use == false) b = solve(next, 1, idx);
        ret += max(a, b);
    }
    if(use) ret += W[idx];
    return ret;
}
int main(){
    int a, b, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &W[i]);
    for(i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%d", max(solve(1,0,0),solve(1,1,0)));
}