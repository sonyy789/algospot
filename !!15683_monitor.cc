#include <cstdio>
int n, m, B[10][10], cctvCnt, pos[10][2];
int C[6] = {0, 4, 2, 4, 4, 1};
int P[6] = {0, 1, 2, 2, 3, 4};
int dir[4][2] = {{-1,0},{0, -1},{1,0},{0,1}};
void monitor(int y, int x, int d, int add){
   int num = B[y][x];
   for(int i = 0; i < P[num]; i++, d=(d+1)%4){
      int ny = y, nx = x, ay = dir[d][0], ax = dir[d][1];
      while(1){
         ny += ay, nx += ax;
         if(B[ny][nx] == 6) break;
         if(B[ny][nx] > 0 && B[ny][nx] < 6) continue;
         B[ny][nx] += add;
      }
      if(num == 2) d++;
   }
}
int solve(int idx){
   if(idx == cctvCnt){
      int cnt = 0;
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <=m; j++)
            if(B[i][j] == 0) cnt++;
      return cnt;
   }
   int y = pos[idx][0], x = pos[idx][1];
   int num = B[y][x], ret = 1e9;
   for(int i = 0; i < C[num]; i++){
      monitor(y, x, i, 100);
      int res = solve(idx+1);
      monitor(y, x, i, -100);
      ret = ret < res ? ret : res;
   }
   return ret;
}
int main(){
   char c;
   scanf("%d%d", &n, &m);
   for(int i = 1; i <= n; i++){
      B[i][0] = B[i][n+1] = 6;
      for(int j = 1; j <= m; j++){
         B[0][j] = B[n+1][j] = 6;
         scanf(" %c", &c);
         B[i][j] = c-'0';
         if(B[i][j] > 0 && B[i][j] < 6) 
            pos[cctvCnt][0] = i, pos[cctvCnt++][1] = j; 
      }
   }
   printf("%d",solve(0));
}