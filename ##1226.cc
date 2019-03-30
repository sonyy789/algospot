#include <cstdio>
#include <queue>
#include <cstring>
#define N 16
using namespace std;
int t, z, sy, sx, dy, dx;
char A[20][20];
int D[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool visited[20][20];
int main(){
    int i, j;
    for(z = 1; z <= 10; z++){
        scanf("%d", &t);
        memset(&visited, 0, sizeof(visited));
        for(i = 1; i <= N; i++){
            scanf("%s", A[i]+1);
            for(j = 1; j <= N; j++){
                if(A[i][j] == '1') visited[i][j] = true;
                else if(A[i][j] == '2') sy = i, sx = j;
                else if(A[i][j] == '3') dy = i, dx = j;
            }
        }
        queue<pair<int, int>> q;
        q.push({sy, sx});
        visited[sy][sx] = true;
        while(!q.empty()){
            int y = q.front().first, x = q.front().second;
            q.pop();
            if(y == dy && x == dx) break;
            for(i = 0; i < 4; i++){
                int ny = y+D[i][0], nx = x+D[i][1];
                if(ny < 1 || nx < 1 || ny > N || nx > N || visited[ny][nx]) continue;
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
        printf("#%d %d\n", t, visited[dy][dx]?1:0);
    }
}