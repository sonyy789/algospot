#include <cstdio>
#include <queue>
using namespace std;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int A[21][21], V[21][21];
int n, ty, tx, dist;
void bfs(int y, int x, int size){
    queue<pair<int, pair<int, int>>> q;
    q.push({0,{y,x}});
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) V[i][j] = 0;
    V[y][x] = 1;
    while(!q.empty()){
        int cost = q.front().first;
        if(cost > dist) break;
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        q.pop();
        if(A[cy][cx] && A[cy][cx] < size && cost <= dist){
            dist = cost;
            if(cy < ty || (cy == ty && cx < tx)) ty = cy, tx = cx;
        }
        for(int i = 0; i < 4; i++){
            int ny = cy+dy[i], nx = cx+dx[i];
            if(V[ny][nx] || A[ny][nx] > size) continue;
            V[ny][nx] = 1;
            q.push({cost+1,{ny,nx}});
        }
    }
}
int main(){
    int cy, cx, size =1, eatCnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            scanf("%d", &A[i][j]);
            if(A[i][j] == 9){
                cy = i, cx = j;
                A[i][j] = 0;
            }
        }
    for(int i = 1; i <= n; i++)
        V[i][0] = V[0][i] = V[n+1][i] = V[i][n+1] = 1;
    int ans = 0;
    while(1){
        if(eatCnt == 0) eatCnt = ++size;
        dist = 1e9; ty = 21, tx = 21;
        bfs(cy, cx, size);
        if(dist == 1e9) break;
        cy = ty, cx = tx;
        A[cy][cx] = 0;
        eatCnt--;
        ans += dist;
    }
    printf("%d", ans);
}