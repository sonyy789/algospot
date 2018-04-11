#include <cstdio>
#include <queue>
#include <unistd.h>
using namespace std;
int M[51][51];
bool visit[51][51];
int r, c, a;
int dy, dx;
queue<pair<int, int>> q[2];
int bfs(int idx){
    M[q[idx].front().first][q[idx].front().second] = 0;
    while(!q[idx].empty()){
        int y = q[idx].front().first;
        int x = q[idx].front().second;
        visit[y][x] = true;
        q[idx].pop();
        int val = M[y][x]+1;
        if(y-1 >= 0 && M[y-1][x] > val && !visit[y-1][x]) {q[idx].push(make_pair(y-1, x)); M[y-1][x] = val; visit[y-1][x] = true;}
        if(x-1 >= 0 && M[y][x-1] > val && !visit[y][x-1]) {q[idx].push(make_pair(y, x-1)); M[y][x-1] = val; visit[y][x-1] = true;}
        if(y+1 < r && M[y+1][x] > val && !visit[y+1][x]) {q[idx].push(make_pair(y+1, x)); M[y+1][x] = val; visit[y+1][x] = true;}
        if(x+1 < c && M[y][x+1] > val && !visit[y][x+1]) {q[idx].push(make_pair(y, x+1)); M[y][x+1] = val; visit[y][x+1] = true;}
    }
    int ret = M[dy][dx];
    M[dy][dx] = 1e4;
    return ret;
}
int main(){
    char in[51];
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++){
        scanf("%s", in);
        for(int j = 0; j < c; j++){
            a = 1e4;
            if(in[j] == 'D') {
                dy = i; dx = j;
                a = -1;
            }else if(in[j] == 'S') {
                q[1].push(make_pair(i,j));
            }else if(in[j] == '*'){
                q[0].push(make_pair(i,j));
                a = -1;
            }else if(in[j] == 'X') {a = -1;}
            M[i][j] = a;
        }
    }
    bfs(0);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) visit[i][j] = false;
    int ans = bfs(1);
    if(ans == 1e4) printf("KAKTUS");
    else printf("%d\n", ans);
    
}