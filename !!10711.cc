#include <cstdio>
#include <queue>
using namespace std;
struct Point{
    int y,x;
};
int h, w, ans;
int E[1001][1001];
int D[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
char land[1002][1002];
int main(){
    int i, j, k, a = 0, b = 1;
    scanf("%d%d", &h, &w);
    for(i = 1; i <= h; i++)
        scanf("%s", land[i]+1);
    for(i = 2; i < h; i++)
        for(j = 2; j < w; j++){
            if(land[i][j]=='.') continue;
            for(k = 0; k < 8; k++){
                int ny = i+D[k][0], nx = j+D[k][1];
                if(land[ny][nx] == '.') E[i][j]++;
            }
        }
    queue<Point> q[2];
    for(i = 2; i < h; i++)
        for(j = 2; j < w; j++){
            if(land[i][j] == '.') continue;
            if(E[i][j] >= (land[i][j]-'0')) q[a].push({i,j}), land[i][j] = '.';
        }
    while(!q[a].empty()){
        while(!q[a].empty()){
            int y = q[a].front().y, x = q[a].front().x;
            q[a].pop();
            for(k = 0; k < 8; k++){
                int ny = y+D[k][0], nx = x+D[k][1];
                E[ny][nx]++;
                if(land[ny][nx] != '.' && E[ny][nx]>=(land[ny][nx]-'0')){ 
                    land[ny][nx] = '.';
                    q[b].push({ny,nx});
                }
            }
        }
        ans++;
        swap(a,b);
    }
    printf("%d", ans);
}