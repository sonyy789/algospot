#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Point{
    int c,y,x;
};
int n, m, k, sy, sx, dy, dx;
int dp[1001][1001];
int D[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
char A[1002][1002];
int main(){
    int i, j;
    for(i = 1; i <= 1000; i++)
        for(j = 1; j <= 1000; j++) dp[i][j] = 1e9;
    scanf("%d%d%d", &n, &m, &k);
    for(i = 1; i <= n; i++)
        scanf("%s", A[i]+1);
    scanf("%d%d%d%d", &sy, &sx, &dy, &dx);
    queue<Point> q;
    if(A[sy][sx] == '.') q.push({0,sy,sx});
    dp[sy][sx] = 0;
    while(!q.empty()){
        Point t = q.front();
        q.pop();
        if(t.y == dy && t.x == dx){
            printf("%d", dp[dy][dx]);
            return 0;
        }
        for(i = 0; i < 4; i++){
            int ny = t.y+D[i][0], nx = t.x+D[i][1];
            for(j = 1; j <= k; j++, ny += D[i][0], nx += D[i][1]){
                if(ny < 1 || nx < 1 || ny > n || nx > m || A[ny][nx] == '#') break;
                if(t.c+1 >= dp[ny][nx]) continue;
                dp[ny][nx] = t.c+1;
                q.push({dp[ny][nx], ny, nx});
            }
        }
    }
    printf("-1");
}