#include <cstdio>
using namespace std;
int B[52][52];
int w, h;
int D[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
void dfs(int y, int x){
    int ny, nx, i, j;
    B[y][x] = 0;
    for(i = 0; i < 8; i++){
        ny = y+D[i][0], nx = x+D[i][1];
        if(B[ny][nx]) dfs(ny,nx);
    }
}
int main(){
    int i, j;
    while(1){
        scanf("%d%d", &w, &h);
        if((w|h) == 0) break;
        for(i = 1; i <= h; i++)
            for(j = 1; j <= w; j++) 
                scanf("%d", &B[i][j]);
        int cnt = 0;
        for(i = 1; i <= h; i++)
            for(j= 1; j <= w; j++)
                if(B[i][j]) dfs(i, j), cnt++;
        printf("%d\n", cnt);
    }
}