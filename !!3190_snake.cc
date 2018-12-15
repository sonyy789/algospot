#include <cstdio>
int B[102][102];
int L[101];
char C[101];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int main(){
   int n, k, l, x, a, b;
   char c;
   scanf("%d%d", &n, &k);
   for(int i = 1; i <= 100; i++)
      B[0][i] = B[i][0] = B[n+1][i] = B[i][n+1] = 2;
   for(int i = 0; i < k; i++){
      scanf("%d%d", &a, &b);
      B[a][b] = 1;
   }
   scanf("%d", &l);
   for(int i = 0; i < l; i++){
      scanf("%d %c", &a, &c);
      L[i] = a; C[i] = c;
   }
   int dir = 2, cnt = 2, tmpDir, idx = 0;
   int hy = 1, hx = 1, ty = 1, tx = 1;
   B[hy][hx] = cnt;
   for(int i = 1;; i++){
      hy += dy[dir]; hx += dx[dir];
      int val = B[hy][hx]; B[hy][hx] = ++cnt;
      if(val > 1) {i += l; break;}
      else if(val != 1){
         for(int j = 0; j < 4; j++)
            if(B[ty][tx]+1==B[ty+dy[j]][tx+dx[j]]){   
               tmpDir = j; break;
            }
            B[ty][tx] = 0;
            ty += dy[tmpDir]; tx += dx[tmpDir];
      }
      if(L[idx] == i){
         if(C[idx] == 'D') dir = (dir+1)%4;
         else dir = (dir+3)%4;
         idx++;
      }
   }
   printf("%d\n", cnt-2);
}