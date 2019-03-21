#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Point{
    int y, x, dir;
};
int n, door_idx, inf = 1e9;
int D[4][2] = {{0,1},{-1,0},{0,-1},{1,0}}, door[2][2];
int dp[51][51][4];
char A[52][52];
int main(){
    int i, j, k;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%s", A[i]+1);
        for(j = 1; j <= n; j++){
            if(A[i][j] == '#') door[door_idx][0] = i, door[door_idx++][1] = j;
            for(k = 0; k < 4; k++) dp[i][j][k] = inf;
        }
    }
    queue<Point> q;
    for(i = 0; i < 4; i++){
        int y = door[0][0]+D[i][0];
        int x = door[0][1]+D[i][1];
        if(y < 1 || x < 1 || y > n || x > n || A[y][x] == '*') continue;
        q.push({y, x, i});
        dp[y][x][i] = 0;
    }
    while(!q.empty()){
        int y = q.front().y, x = q.front().x;
        int dir = q.front().dir;
        q.pop();
        if((y == door[1][0] && x == door[1][1])){ continue;}
        if(A[y][x] == '!'){
            if(dir&1){
                for(i = 0; i < 3; i+=2){
                    int ny = y+D[i][0], nx = x+D[i][1];
                    if(ny < 1 || nx < 1 || ny > n || nx > n || A[ny][nx] == '*') continue;
                    if(dp[y][x][dir]+1 < dp[ny][nx][i]){
                        dp[ny][nx][i] = dp[y][x][dir]+1;
                        q.push({ny, nx, i});
                    }
                }
            }else{
                for(i = 1; i < 4; i+=2){
                    int ny = y+D[i][0], nx = x+D[i][1];
                    if(ny < 1 || nx < 1 || ny > n || nx > n || A[ny][nx] == '*') continue;
                    if(dp[y][x][dir]+1 < dp[ny][nx][i]){
                        dp[ny][nx][i] = dp[y][x][dir]+1;
                        q.push({ny, nx, i});
                    }
                }
            }
        }
        int ny = y+D[dir][0], nx = x+D[dir][1];
        if(ny < 1 || nx < 1 || ny > n || nx > n || A[ny][nx] == '*') continue;
        if(dp[y][x][dir] < dp[ny][nx][dir]){
            dp[ny][nx][dir] = dp[y][x][dir];
            q.push({ny, nx, dir});
        }
    }
    int y = door[1][0], x = door[1][1];
    printf("%d", min(min(dp[y][x][0], dp[y][x][1]), min(dp[y][x][2], dp[y][x][3])));
}