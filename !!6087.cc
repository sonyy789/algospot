#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct Point {
    int c, y, x, dir;
    bool operator<(const Point &P)const {
        return c<P.c;
    }
};
int w, h;
int B[3] = {0, 1, 1};
int C[2][2], D[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int dp[101][101][4];
char A[102][102];
int main(){
    int i, j, k, c_idx = 0;
    scanf("%d%d", &w, &h);
    for(i = 1; i <= h; i++){
        scanf("%s", A[i]+1);
        for(j = 1; j <= w; j++){
            if(A[i][j] == 'C')
                C[c_idx][0] = i, C[c_idx++][1] = j;
        }
    }
    for(i = 1; i < 101; i++)
        for(j = 1; j < 101; j++)
            for(k = 0; k < 4; k++) dp[i][j][k] = 1e9;
    priority_queue<Point> pq;
    for(i = 0; i < 4; i++){
        int ny = C[0][0]+D[i][0], nx = C[0][1]+D[i][1];
        if(ny < 1 || nx < 1 || ny > h || nx > w || A[ny][nx] == '*') continue;
        pq.push({0, ny, nx, i});
        dp[ny][nx][i] = 0;
    }
    while(!pq.empty()){
        int y = pq.top().y, x = pq.top().x, dir = pq.top().dir, t_dir = dir;
        pq.pop();
        if(y == C[1][0] && x == C[1][1]) break;
        for(i = 0; i < 3; t_dir = (t_dir+i+1)%4, i++){
            int ny = y+D[t_dir][0], nx = x+D[t_dir][1];
            if(ny < 1 || nx < 1 || ny > h || nx > w || A[ny][nx] == '*') continue;
            if(dp[ny][nx][t_dir] > dp[y][x][dir]+B[i]){
                dp[ny][nx][t_dir] = dp[y][x][dir]+B[i];
                pq.push({-dp[ny][nx][t_dir], ny, nx, t_dir});
            }
        }
    }
    int ans = 1e9;
    for(i = 0; i < 4; i++) ans = min(ans, dp[C[1][0]][C[1][1]][i]);
    printf("%d", ans);
}