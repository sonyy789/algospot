#include <cstdio>
char chk[2] = {'B', 'W'};
char board[51][51], in[51];
int min(int a, int b){return a<b?a:b;}
int solve(int y, int x){
    int ret = 0;
    char curr = board[y][x]=='B'?0:1;
    for(int i = y; i < y+8; i++){
        for(int j = x; j < x+8; j++){
            if(chk[curr] != board[i][j]) ret++;
            curr = (curr+1)%2;
        }
        curr = (curr+1)%2;
    }
    return ret<64-ret?ret:64-ret;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", in);
        for(int j = 0; j < m; j++)
            board[i][j] = in[j];
    }
    int ans = 64;
    n -= 8; m -= 8;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m;j++)
            ans = min(ans, solve(i, j));
    printf("%d\n", ans);
}