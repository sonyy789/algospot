#include <cstdio>
#include <cstring>
int nCnt, tCnt, cnt = 0, n, m, A[302][302];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool V[302][302];
void dfs(int y, int x){
   V[y][x] = true; tCnt++;
   int ny, nx, zero = 0;
   for(int i = 0; i < 4; i++){
      ny = y+dy[i]; nx = x+dx[i];
      if(V[ny][nx]) continue;
      if(A[ny][nx] > 0) dfs(ny, nx);
      else zero++;
   }
   A[y][x] -= zero;
   if(A[y][x] > 0) nCnt++;
}
int main(){
   scanf("%d%d", &n, &m);
   memset(&A, 0, sizeof(A));
   for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++){
         scanf("%d", &A[i][j]);
         if(A[i][j]) cnt++;
      }
   int ans = 0;
   while(cnt){
      nCnt = tCnt = 0;
      memset(&V, false, sizeof(V));
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <=m; j++)
            if(A[i][j] > 0){
               dfs(i,j);
               i += n; j += m;
            }
      if(tCnt != cnt) break;
      ans++;
      cnt = nCnt;
   }
   if(cnt == 0) printf("0");
   else printf("%d", ans);
}