#include <cstdio>
#include <cstring>
using namespace std;
int t, r, c;
int D[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int visited[21][21][16][4];
char A[22][22];
bool solve(int y, int x, char mem, int dir){
    if(visited[y][x][mem][dir]) return false;
    visited[y][x][mem][dir] = true;
    bool f = true;
    if(A[y][x] == '@') return true;
    else if(A[y][x] == '>') dir = 0;
    else if(A[y][x] == 'v') dir = 1;
    else if(A[y][x] == '<') dir = 2;
    else if(A[y][x] == '^') dir = 3;
    else if(A[y][x] == '_') dir = mem?2:0;
    else if(A[y][x] == '|') dir = mem?3:1;
    else if(A[y][x] == '-') mem = mem==0?15:mem-1;
    else if(A[y][x] == '+') mem = mem==15?0:mem+1;
    else if(0 <= A[y][x]-'0' && A[y][x]-'0' <= 9) mem = A[y][x]-'0';
    else if(A[y][x] == '?'){
        f = false;
        for(int i = 0; i < 4; i++)
            if(solve((y+D[i][0])%r, (x+D[i][1])%c, mem, i)) return true;
    }
    if(f) if(solve((y+D[dir][0])%r, (x+D[dir][1])%c, mem, dir)) return true;
    return false;
}
int main(){
    int i, j, z;
    scanf("%d", &t);
    for(z = 1; z <= t; z++){
        memset(&visited, 0, sizeof(visited));
        scanf("%d%d", &r, &c);
        D[2][1] = c-1; D[3][0] = r-1;
        for(i = 0; i < r; i++) scanf("%s", A[i]);
        printf("#%d %s\n", z, solve(0,0,0,0)?"YES":"NO");
    }
}