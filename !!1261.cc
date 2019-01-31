#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, i, j;
char maze[103][103];
int dp[103][103];
int D[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    scanf("%d%d",&m,&n);
    for(i = 1; i <= n; i++)
        scanf("%s", maze[i]+1);
    
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++) dp[i][j] = 1e9;
    dp[1][1] = maze[1][1]=='1'?1:0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-dp[1][1], {1,1}});
    while(!pq.empty()){
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        for(i = 0; i < 4; i++){
            int ny = y+D[i][0], nx = x+D[i][1];
            if(ny < 1 || nx < 1 || ny > n || nx > m) continue;
            if(dp[ny][nx] > dp[y][x]+maze[ny][nx]-'0'){
                dp[ny][nx] = dp[y][x]+maze[ny][nx]-'0';
                pq.push({-dp[ny][nx], {ny,nx}});
            }
        }
    }
    printf("%d",dp[n][m]);
}