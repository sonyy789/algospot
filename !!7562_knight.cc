#include <queue>
#include <cstdio>
using namespace std;
int l, yy, xx;
int dy[8] = {-2,-2,-1,-1,1,1,2,2};
int dx[8] = {-1,1,-2,2,-2,2,-1,1};
bool dp[301][301];
int solve(int y, int x){
   int ny, nx, ans = 0, cnt = 1;
   dp[y][x] = true;
   queue<pair<int, int >> q;
   q.push({y,x});
   while(1){
      int tCnt = 0;
      for(int i = 0; i < cnt; i++){
         int qy = q.front().first;
         int qx = q.front().second;
         q.pop();
         if(qy == yy && qx == xx) return ans;
         for(int i = 0; i < 8; i++){
            ny = qy+dy[i]; nx = qx+dx[i];
            if(ny < 0 || nx < 0 || ny >= l || nx >= l || dp[ny][nx]) continue;
            dp[ny][nx] = true;
            q.push({ny, nx}); tCnt++;
         }
      }
      cnt = tCnt;
      ans++;
   }
}
int main(){
   int t, y, x;
   scanf("%d", &t);
   while(t--){
      scanf("%d%d%d%d%d", &l, &y, &x, &yy, &xx);
      for(int i = 0; i < l; i++)
         for(int j = 0; j < l; j++)
            dp[i][j] = false;
      printf("%d\n", solve(y, x));
   }
}