#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

char B[200][200], cmd[53];
int D[4][2] ={{1,0},{0,-1},{-1,0},{0,1}};
int n, i, j, y, x, min_x, min_y, max_x, max_y, dir = 0;

int main(){
    for(i = 1; i < 200; i++)
        for(j = 1; j < 200; j++) B[i][j] = '#';
    B[50][50] = '.';
    y = x = min_x = min_y = max_x = max_y = 50;
    scanf("%d%s", &n,cmd+1);
    for(i = 1; cmd[i]!='\0'; i++){
        if(cmd[i] == 'F'){
            y += D[dir][0], x += D[dir][1];
            B[y][x] = '.';
            if(dir == 0) max_y = max(max_y, y);
            else if(dir == 1) min_x = -max(-min_x, -x);
            else if(dir == 2) min_y = -max(-min_y, -y);
            else max_x = max(max_x, x);//dir == 3
        }else if(cmd[i] == 'L'){
            dir = (dir+3)%4;
        }else{ // R
            dir = (dir+1)%4; 
        }
    }
    for(i = min_y; i <= max_y; i++){
        for(j = min_x; j <= max_x; j++)
            printf("%c",B[i][j]);
        printf("\n");
    }
}