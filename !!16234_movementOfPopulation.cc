#include <cstdio>
#include <cmath>
using namespace std;
int n, l, r, idx;
int A[101][101], V[101][101], I[101*101][2];
int dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0};
int dfs(int y, int x){
   int ret = A[y][x];
   V[y][x] = 1; 
   I[idx][0] = y, I[idx++][1] = x;
   for(int i = 0; i < 4; i++){
      int ny = y+dy[i], nx = x+dx[i];
      int inv = abs(A[y][x]-A[ny][nx]);
      if(V[ny][nx] == 0 && inv >= l && inv <= r)
         ret += dfs(ny, nx);
   }
   return ret;
}
int dfsAll(){
   int f = 0;
   for(int i = 1; i <= n; i++)
      for(int j = 1; j <=n; j++) V[i][j] = 0;
   for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
         if(V[i][j] == 0){
            idx = 0;
            int sum = dfs(i, j);
            if(idx > 1){
               f = 1;
               sum /= idx;
               for(int i = 0; i < idx; i++){
                  int y=I[i][0], x = I[i][1];
                  A[y][x] = sum;
               }
            }
         }
   if(f) return 1;
   return 0;
}
int main(){
   scanf("%d%d%d", &n, &l, &r);
   for(int i = 1; i <=n; i++){
      V[i][0] = V[0][i] = V[i][n+1] = V[n+1][i] = 1;
      for(int j = 1; j <=n; j++)
         scanf("%d", &A[i][j]);
   }
   int ans = 0;
   while(dfsAll()){ans++;}
   printf("%d", ans);
}