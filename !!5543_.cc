#include <cstdio>
int main(){
   int a = 2000, b, c = -50, i;
   for(i = 0; i < 3; i++){
      scanf("%d", &b);
      a = a < b ? a:b;
   } c += a;
   a = 2000;
   for(i = 0; i < 2; i++){
      scanf("%d", &b);
      a = a < b?a:b;
   } c += a;
   printf("%d", c);
}