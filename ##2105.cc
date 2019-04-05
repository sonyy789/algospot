#include <cstdio>
#include <algorithm>
using namespace std;
int t, tc, n, sy, sx;
bool eaten[101];
int A[21][21], D[4][2] = {{-1,1},{1,1},{1,-1},{-1,-1}};
int solve(int y, int x, int dir, int sum){
    if(y < 1 || x < 1 || y > n || x > n) return -1;
    if(y == sy && x == sx && dir == 3) return sum-1;
    if(eaten[A[y][x]]) return -1;
    eaten[A[y][x]] = true;
    int ret = solve(y+D[dir][0], x+D[dir][1], dir, sum+1);
    if(dir != 3) ret = max(ret, solve(y+D[dir+1][0], x+D[dir+1][1], dir+1, sum+1));
    eaten[A[y][x]] = false;
    return ret;
}
int main(){
    int i, j;
    scanf("%d", &t);
    for(tc = 1; tc <= t; tc++){
        int ans = -1;
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++) scanf("%d", &A[i][j]);
        for(i = 2; i <= n-1; i++)
            for(j = 1; j < n-1; j++){
                sy = i, sx = j;
                if(A[i][j] == A[i-1][j+1] || A[i][j] == A[i+1][j+1] || A[i+1][j+1] == A[i-1][j+1]) continue;
                ans = max(ans, solve(i, j, 0, 1));
            }
        printf("#%d %d\n", tc, ans);
    }
}