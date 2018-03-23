#include <cstdio>
#include <vector>
#define MAX 1001
using namespace std;
vector<int> edge[MAX];
bool visit[MAX];
int n, m, a, b, ans = 0;
void dfs(int curr){
    visit[curr] = true;
    for(int i = 0; i < edge[curr].size(); i++)
        if(!visit[edge[curr][i]]) dfs(edge[curr][i]);
}
int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &a, &b);
        edge[b].push_back(a);
        edge[a].push_back(b);
    }
    for(int i =1; i <= n; i++)
        if(!visit[i]) {ans++; dfs(i);}
    printf("%d\n", ans);
}