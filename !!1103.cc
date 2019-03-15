#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int A[51][51], dp[51][51];
int D[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool visited[51][51];
int solve(int y, int x){
    if(y < 1 || x < 1 || y > n || x > m || A[y][x] == -1) return 0;
    if(visited[y][x]) return 1e9;
    if(dp[y][x]) return dp[y][x];
    int i, j;
    int &ret = dp[y][x] = 1;
    visited[y][x] = true;
    for(i = 0; i < 4; i++){
        int ny = y+D[i][0]*A[y][x], nx = x+D[i][1]*A[y][x];
        ret = max(ret, solve(ny, nx)+1);
    }
    visited[y][x] = false;
    return ret;
}
int main(){
    int i, j;
    char in[52];
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%s", in+1);
        for(j = 1; j <= m; j++){
            if(in[j] == 'H') A[i][j] = -1;
            else A[i][j] = in[j]-'0';
        }
    }
    int ans = solve(1,1);
    printf("%d", ans >= 1e9?-1:ans);
}