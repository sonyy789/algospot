#include <cstdio>
int t, n, k, maxH, ans;
int A[9][9];
int max(int a, int b) {return a>b?a:b;}
bool visit[9][9];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int solve(int y, int x, bool flag){
    if(y < 0 || x < 0 || x >= n || y >= n) return -1e9;
    int ret = 0;
    visit[y][x] = true;
    for(int i = 0; i < 4; i++){
        int nextY = y+dy[i];
        int nextX = x+dx[i];
        if(!visit[nextY][nextX] && A[nextY][nextX] < A[y][x]) {ret = max(ret, solve(nextY, nextX, flag));}
        else if(!visit[nextY][nextX] && flag && A[nextY][nextX]-k < A[y][x]){
            int store = A[nextY][nextX];
            A[nextY][nextX] = A[y][x]-1; 
            ret = max(ret, solve(nextY, nextX, !flag));
            A[nextY][nextX] = store;
        }
    }
    visit[y][x] = false;
    return ret+1;
}
int main(){
    scanf("%d", &t);
    for(int z = 1; z <= t; z++){
        maxH = ans = 0;
        
        scanf("%d %d" ,&n, &k);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
               scanf("%d", &A[i][j]);
               maxH = max(maxH, A[i][j]);
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(A[i][j] == maxH) { 
                    for(int y = 0; y < n; y++)
                        for(int x = 0; x < n; x++)
                            visit[y][x] = false;
                    ans = max(ans, solve(i, j, true)); 
                }
        printf("#%d %d\n", z, ans);
    }
}