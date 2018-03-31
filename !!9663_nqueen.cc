#include <cstdio>
int n, board[15][15];
int nqueen(int y){
    if(y == n) return 1;
    int ret, add;
    ret = add = 0;
    for(int i = 0; i < n; i++){
        if(board[y][i]) continue;
        for(int j = y; j < n; j++) board[j][i]++;
        add = 0; for(int j = y; j < n && i+add >= 0; j++, add--) board[j][i+add]++;
        add = 0; for(int j = y; j < n && i+add < n; j++, add++) board[j][i+add]++;
        ret += nqueen(y+1);
        for(int j = y; j < n; j++) board[j][i]--; add = 0;
        add = 0; for(int j = y; j < n && i+add >= 0; j++, add--) board[j][i+add]--;
        add = 0;  for(int j = y; j < n && i+add < n; j++, add++) board[j][i+add]--;
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    printf("%d\n", nqueen(0));
}