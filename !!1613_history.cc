#include <cstdio>
bool L[401][401];
int main(){
   int n, k, s, a, b;
   scanf("%d%d", &n, &k);
   while(k--){
      scanf("%d%d", &a, &b);
      L[a][b] = true;
   }
   for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++)
            if(L[i][k]&&L[k][j]) L[i][j] = L[i][k]||L[k][j];
   scanf("%d", &s);
   while(s--){
      scanf("%d%d", &a, &b);
      if(L[a][b]) printf("-1\n");
      else if(L[b][a]) printf("1\n");
      else printf("0\n");
   }
}