#include <cstdio>
int main(){
   int n, a = 10, b = 1;
   scanf("%d", &n);
   while(n > a){
      int val = (n%a)/b;
      if(val >= 5) n += (10-val)*b;
      else n -= val*b;
      a *= 10; b *= 10;
   }
   printf("%d", n);
}