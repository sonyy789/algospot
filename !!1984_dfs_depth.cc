#include <cstdio>
bool visit[26];
char in[21];
int r,c, board[21][21];
int max(int a, int b){return a>b?a:b;}
int dfs(int y, int x){
    int ret = 0;
    visit[board[y][x]] = true;
    if(y-1>=0 && !visit[board[y-1][x]] ) ret = max(ret, dfs(y-1,x));
    if(x-1>=0 && !visit[board[y][x-1]] ) ret = max(ret, dfs(y,x-1));
    if(y+1< r && !visit[board[y+1][x]] ) ret = max(ret, dfs(y+1,x));
    if(x+1< c && !visit[board[y][x+1]] ) ret = max(ret, dfs(y,x+1));
    visit[board[y][x]] = false;
    return ret+1;
}
int main(){
    scanf("%d %d",&r, &c);
    for(int i = 0; i < r; i++){
        scanf("%s", in);
        for(int j = 0; j < c; j++)    
            board[i][j] = in[j]-'A';
    }
    printf("%d\n", dfs(0,0));
}