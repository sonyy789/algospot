#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n, i, j;
int dp[127][127], cave[127][127];
int D[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    for(int game_num = 1;; game_num++){
        scanf("%d", &n);
        if(n == 0) break;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++){
                scanf("%d", &cave[i][j]);
                dp[i][j] = 1e9;
            }
        dp[1][1] = cave[1][1];
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({-dp[1][1],{1,1}});
        while(!pq.empty()){
            int y = pq.top().second.first;
            int x = pq.top().second.second;
            pq.pop();
            for(i = 0; i < 4; i++){
                int ny = y+D[i][0], nx = x+D[i][1];
                if(ny < 0 || nx < 0 || ny > n || nx > n) continue;
                if(dp[ny][nx] > dp[y][x]+cave[ny][nx]){
                    dp[ny][nx] = dp[y][x]+cave[ny][nx];
                    pq.push({-dp[ny][nx], {ny,nx}});
                }
            }
        }
        printf("Problem %d: %d\n", game_num,dp[n][n]);
    }
}