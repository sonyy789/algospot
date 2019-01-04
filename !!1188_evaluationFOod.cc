#include <cstdio>
int main(){
   int a, b, c = 0;
   scanf("%d%d", &a, &b);
   for(int i = a; i <= a*b; i+=a){
      if(i%b==0) continue;
      c++;
   }
   printf("%d", c);
}