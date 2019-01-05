#include <cstdio>
int n, r, s, y, x, A[10][10];
void solve(int y, int x){
   printf("%d",x+1);
   if(y== -1) return;
   s = 0;
   for(int j = 0; j <= x; j++){
      if(n <= A[y][j]+s){n-=s;solve(y-1, j-1); return;}
      s += A[y][j];
   }
}
int main(){
   for(int i = 0; i < 10; i++) A[0][i] = 1;
   for(int i = 1; i < 10; i++){
      s = 0;
      for(int j = i; j < 10; j++){
         s += A[i-1][j-1];
         A[i][j] = s;
      }
   }
   scanf("%d", &n);
   s = -1;
   for(int i = 0; i < 10; i++)
      for(int j = i; j < 10; j++){
         if(n <= A[i][j]+s){ n-=s; solve(i-1, j-1);  return 0;}
         s += A[i][j];
      }
   printf("-1");
}