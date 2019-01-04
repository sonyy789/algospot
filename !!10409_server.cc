#include <cstdio>
int main(){
   int a, n, t;
   scanf("%d%d", &n, &t);
   for(int i = 0; i < n; i++){
      scanf("%d", &a); t -= a;
      if(t < 0) {printf("%d",i); return 0;}
   }
   if(t >=0) printf("%d", n);
}