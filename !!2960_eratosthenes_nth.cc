#include <cstdio>
bool V[1001];
int main(){
   int n, k, i, j;
   scanf("%d%d", &n, &k);
   for(i = 2; i <= n; i++){
      if(V[i]) continue;
      for(int j = i; j <= n; j+=i)
         if(!V[j]){
            V[j] = true;
            if(--k == 0){printf("%d", j); return 0;}
         }
   }
}