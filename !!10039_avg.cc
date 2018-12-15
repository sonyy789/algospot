#include <cstdio>
int main(){
   int n, ans = 0;
   for(int i = 0; i < 5; i++){
      scanf("%d", &n);
      if(n < 40) n = 40;
      ans += n;
   }
   printf("%d\n", ans/5);
}