#include <cstdio>
int main(){
   int n, a, sum = 0;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++){
      scanf("%d", &a);
      a = i*a-sum; sum += a;
      printf("%d ",a);
   }
}