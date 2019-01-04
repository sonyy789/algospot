#include <cstdio>
int main(){
   int c, k, a = 1;
   scanf("%d%d", &c, &k);
   while(k--) {a *= 10;}
   k = (c/a)*a; c %= a;
   if(c >= a/2) k+=a;
   printf("%d", k);
}