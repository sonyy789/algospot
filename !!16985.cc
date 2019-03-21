#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
struct Point{
    int d, y, x, idx;
    bool operator<(const Point &P){ return d<P.d; }
};
int ans = 1e9;
int O[5], O2[5];
int D[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int dp[5][5][5];
int B[5][4][5][5];
bool check[5];
unordered_map<int, bool> um;
void dijkstra(int y, int x){
    int i, j, k, ny, nx;
    for(k = 0; k < 5; k++)
        for(i = 0; i < 5; i++)
            for(j = 0; j < 5; j++)
                dp[k][i][j] = 1e9;
    queue<Point> q;
    q.push({0, 0, 0, 0});
    dp[O[0]][0][0] = 0;
    while(!q.empty()){
        int y = q.front().y, x = q.front().x, idx = q.front().idx, d = -q.front().d; 
        q.pop();
        for(i = 0; i < 4; i++){
            ny = y+D[i][0], nx = x+D[i][1];
            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || B[O[idx]][O2[idx]][ny][nx] == 0) continue;
            if(dp[O[idx]][ny][nx] > dp[O[idx]][y][x]+1){
                dp[O[idx]][ny][nx] = dp[O[idx]][y][x]+1;
                q.push({-dp[O[idx]][ny][nx], ny, nx, idx});
            }
            if(idx == 4 && ny == 4 && nx == 4){ 
                ans = min(ans, dp[O[4]][4][4]);
                return;
            }
        }
        if(idx != 0 && B[O[idx-1]][O2[idx-1]][y][x] == 1 && dp[O[idx-1]][y][x] > dp[O[idx]][y][x]+1){
                dp[O[idx-1]][y][x] = dp[O[idx]][y][x]+1;
                q.push({-dp[O[idx-1]][y][x], y, x, idx-1});
        }
        if(idx < 4 && B[O[idx+1]][O2[idx+1]][y][x] == 1 && dp[O[idx+1]][y][x] > dp[O[idx]][y][x]+1){
                dp[O[idx+1]][y][x] = dp[O[idx]][y][x]+1;
                q.push({-dp[O[idx+1]][y][x], y, x, idx+1});
                if(idx+1 == 4 && y == 4 && x == 4){ 
                    ans = min(ans, dp[O[4]][4][4]);
                    return;
                }
        }
    }
}
void perm2(int depth){
    if(depth == 5){
        if(B[O[0]][O2[0]][0][0]){
            dijkstra(0,0);
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        O2[depth] = i;
        perm2(depth+1);
    }
}
void perm(int depth){
    int i, j, idx;
    if(depth == 5){
        int a = 0, b = 0;
        for(idx = 0, i = 1, j = 10000; idx < 5; i *= 10, j /= 10,idx++){
            a += (O[idx]+1)*i;
            b += (O[idx]+1)*j;
        }
        if(um[a] || um[b]) return;
        um[a] = um[b] = true;
        perm2(0);
        return;
    }
    for(i = 0; i < 5; i++){
        if(check[i]) continue;
        check[i] = true;
        O[depth] = i;
        perm(depth+1);
        check[i] = false;
    }
}
int main(){
    int k, l, i, j;
    for(k = 0; k < 5; k++){
        for(i = 0; i < 5; i++)
            for(j = 0; j < 5; j++)
                scanf("%d", &B[k][0][i][j]);
        for(l = 1; l < 4; l++){
            for(i = 0; i < 5; i++)
                for(j = 0; j < 5; j++)
                    B[k][l][j][5-i-1] = B[k][l-1][i][j];
        }
    }
    perm(0);
    printf("%d", ans==1e9?-1:ans);
}