#include <cstdio>
char A[101][101];
int main(){
   int r, c, r2, c2;
   scanf("%d%d",&r,&c);
   r2 = r*2, c2 = c*2;
   for(int i = 1; i <= r; i++)
      for(int j = 1; j <= c; j++){
         scanf(" %c", &A[i][j]);
         A[i][c2-j+1] = A[r2-i+1][j] = A[r2-i+1][c2-j+1] = A[i][j];
      }
   scanf("%d%d", &r, &c);
   A[r][c] = A[r][c]=='#'?'.':'#';
   for(int i = 1; i <= r2; i++){
      for(int j = 1; j <= c2; j++)
         printf("%c",A[i][j]);
      printf("\n");
   }
}