#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool visit[101][101];
int n, m, k, a, b, c, d;
int dfs(int y, int x){
    int ret = 1;
    visit[y][x] = true;
    if(!visit[y-1][x] && y-1 >= 0) ret += dfs(y-1, x);
    if(!visit[y][x-1] && x-1 >= 0) ret += dfs(y, x-1);
    if(!visit[y+1][x] && y+1 < m) ret += dfs(y+1, x);
    if(!visit[y][x+1] && x+1 < n) ret += dfs(y, x+1);
    return ret;
}
int main(){
    vector<int> ans;
    scanf("%d %d %d", &m, &n, &k);
    while(k--){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int i = b; i < d; i++)
            for(int j = a; j < c; j++)
                visit[i][j] = true;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            if(!visit[i][j]) ans.push_back(dfs(i, j));
    }
    sort(ans.begin(), ans.end());
    int size = ans.size();
    printf("%d\n", size);
    for(int data : ans)
        printf("%d ", data);
}