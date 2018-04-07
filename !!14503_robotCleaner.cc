#include <cstdio>
int r, c, A[51][51]; 
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    int i, j, x, y, idx, cnt = 0;
    scanf("%d %d %d %d %d", &r, &c, &y, &x, &idx);
    for(i = 0; i <= r+1; i++) A[i][0] = A[i][c+1] = 1;
    for(i = 0; i <= c+1; i++) A[0][i] = A[r+1][i] = 1;
    for(i = 1; i <= r; i++)
        for(j = 1; j <= c; j++) scanf("%d", &A[i][j]);
    int ans = 0;
    x++; y++;
    while(1){
        if(!A[y][x]) {ans++; A[y][x] = 2;}
        idx = (idx+3)%4; cnt++;
        int ny = dir[idx][0]+y; 
        int nx = dir[idx][1]+x;
        if(A[ny][nx] == 0){
            y = ny; x = nx;
            cnt = 0;
        }
        if(cnt == 4){
            int by = y+dir[(idx+2)%4][0];
            int bx = x+dir[(idx+2)%4][1]; 
            if(A[by][bx] == 1) break;
            else{
                y = by; x = bx;
                cnt =0;
            }
        }
    }
    printf("%d\n", ans);
}