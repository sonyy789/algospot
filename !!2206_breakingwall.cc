#include <cstdio>
#include <queue>
using namespace std;
struct Point{
    int idx,y,x;
};
int n, m, ny, nx, i, j;
char A[1002][1002];
int D[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int dp[2][1001][1001];
bool visit[2][1001][1001];
int main(){
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        scanf("%s", A[i]+1);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++) dp[0][i][j]= dp[1][i][j] = 1e9;
    queue<Point> q;
    q.push({0,1,1});
    visit[0][1][1] = true;
    dp[0][1][1] = 1;
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int idx = q.front().idx;
        q.pop();
        for(i = 0; i < 4; i++){
            ny = y+D[i][0], nx = x+D[i][1];
            if(ny < 1 || nx < 1 || ny > n || nx > m) continue;
            if(visit[idx][ny][nx]) continue;
            visit[idx][ny][nx] = true;
            if(A[ny][nx] == '1'){
                if(idx) continue;
                dp[1][ny][nx] = min(dp[1][ny][nx], dp[0][y][x]+1);
                q.push({1,ny,nx});
            }else{
                dp[idx][ny][nx] = min(dp[idx][ny][nx], dp[idx][y][x]+1);
                q.push({idx,ny,nx});
            }
        }
    }
    int ans = min(dp[0][n][m], dp[1][n][m]);
    printf("%d", ans == 1e9?-1:ans);
}