#include <cstdio>
int n, A[502][502], dp[501][501];
void max(int &a, int b){a = a>b ? a:b;}
int solve(int y, int x){
    int &r = dp[y][x];
    if(r) return r;
    r = 1;
    if(A[y][x] < A[y-1][x]) max(r, solve(y-1,x)+1);
    if(A[y][x] < A[y][x-1]) max(r, solve(y,x-1)+1);
    if(A[y][x] < A[y+1][x]) max(r, solve(y+1,x)+1);
    if(A[y][x] < A[y][x+1]) max(r, solve(y,x+1)+1);
    return r;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            int res = solve(i, j);
            if(res > A[0][0]) A[0][0] = res;
        }
    printf("%d\n", A[0][0]);
}