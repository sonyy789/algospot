#include <cstdio>
#include <unistd.h>
int B[102][102], dir[102];
int main(){
    int a, b, n, m, y, x,idx = 0, P[101][2];
    char D[5] = {'W', 'N', 'E', 'S'};
    char cmd;
    scanf("%d%d%d%d", &a, &b, &n, &m);
    for(int i = 1; i <= n; i++){
        scanf(" %d %d %c",&x,&y, &cmd);
        P[i][0] = b-y+1, P[i][1] = x;
        B[b-y+1][x] = i;
        if(cmd =='W') dir[i] = 0;
        else if(cmd =='N') dir[i] = 1;
        else if(cmd =='E') dir[i] = 2;
        else dir[i] = 3;
    }
    for(int i = 1; i <= a; i++) B[0][i] = B[b+1][i] = -1;
    for(int i = 1; i <= b; i++) B[i][0] = B[i][a+1] = -1;
    int res = 0;
    while(m--){
        scanf("%d %c %d", &a, &cmd, &b);
        if(cmd == 'L'){for(int i = 1; i <= b; i++) dir[a] = (dir[a]+3)%4;}
        else if(cmd == 'R'){for(int i = 1; i <= b; i++) dir[a] = (dir[a]+1)%4;}
        else{
            int f = 0;
            int ay, ax;
            if(dir[a] == 0) ay= 0, ax = -1;
            else if(dir[a] == 1) ay = -1, ax = 0;
            else if(dir[a] == 2) ay = 0, ax = 1;
            else ay = 1, ax = 0;
            for(int i = 1; i <= b; i++){
                res = B[P[a][0]+ay*i][P[a][1]+ax*i];
                if(res) {f = 1; break;}
            }
            if(f) break;
            int tmp = B[P[a][0]][P[a][1]];
            B[P[a][0]][P[a][1]] = 0;
            P[a][0] += ay*b; P[a][1] += ax*b; 
            B[P[a][0]][P[a][1]] = tmp;
        }
    }
    if(res < 0) printf("Robot %d crashes into the wall",a);
    else if(res > 0) printf("Robot %d crashes into robot %d", a,res);
    else printf("OK");
}