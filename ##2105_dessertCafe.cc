#include <cstdio>
int t, n, yy, xx;
bool visit[101];
int A[101][101];
int max(int a, int b){return a>b?a:b;}
int dy[4] = {-1, 1, 1, -1};
int dx[4] = {1, 1, -1, -1};
int solve(int y, int x, int dirIdx, int depth){
    if(dirIdx == 4) return -1;
    if(y < 0 || x < 0 || x >= n || y >= n) return -1;
    if(depth > 0 && y == yy && x == xx) return depth;
    if(visit[A[y][x]]) return -1;
    visit[A[y][x]] = true;
    int nextY = y+dy[dirIdx];
    int nextX = x+dx[dirIdx];
    int ret = solve(nextY, nextX, dirIdx, depth+1);
    ret = max(ret, solve(nextY, nextX, dirIdx+1, depth+1));
    visit[A[y][x]] = false;
    return ret;
}
int main(){
    scanf("%d", &t);
    for(int z = 1; z <= t; z++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) scanf("%d", &A[i][j]);
        int ans = -1;
        for(int i = 1; i < n-1; i++)
            for(int j = 0; j < n-2; j++){ 
                yy = i; xx = j;
                ans = max(ans, solve(i, j, 0, 0));
            }
        printf("#%d %d\n", z, ans);
    }
}