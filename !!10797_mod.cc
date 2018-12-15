#include <cstdio>
int main(){
   int n, a, ans = 0;
   scanf("%d", &n);
   for(int i = 0; i < 5; i++){
      scanf("%d",&a);
      ans += (a%10)==n;
   }
   printf("%d\n", ans);
}