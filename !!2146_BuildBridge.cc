#include <cstdio>
int n, a = 0, b= 1, ny, nx, val = 2, cnt = 0;
int A[101][101], Q[2][10001];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
void dfsSet(int y, int x){
   A[y][x] = val;
   int flag = 1;
   for(int i = 0; i < 4; i++){
      ny = y+dy[i]; nx = x+dx[i];
      if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
      if(A[ny][nx] == 1) dfsSet(ny, nx);
      flag = flag&&A[ny][nx]; 
   }
   if(flag == 0) Q[a][cnt++] = y*n+x;
}
int main(){
   scanf("%d", &n);
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         scanf("%d",&A[i][j]);
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         if(A[i][j] == 1) dfsSet(i, j), val++;
   int y, x, ans = 0;
   while(1){
      int tCnt = 0;
      for(int i = 0; i < cnt; i++){
         y = Q[a][i]/n, x = Q[a][i]%n;
         for(int j = 0; j < 4; j++){
            ny = y+dy[j]; nx = x+dx[j];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || A[ny][nx] == A[y][x]) continue;
            if(!A[ny][nx]){
               A[ny][nx] = A[y][x];
               Q[b][tCnt++] = ny*n+nx;
            }else{
               if(A[ny][nx] < A[y][x]) printf("%d", ans+1);
               else printf("%d", ans);
               return 0;
            }         
         }
      }
      int tmp = a;
      a = b;
      b = tmp;
      cnt = tCnt;
      ans += 2;
   }
}

