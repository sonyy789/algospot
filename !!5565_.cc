#include <cstdio>
int main(){
   int a, b, i;
   scanf("%d", &a);
   for(i = 0; i < 9; i++){
      scanf("%d", &b);
      a -= b;
   }
   printf("%d", a);
}