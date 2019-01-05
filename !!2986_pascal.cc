#include <cstdio>
int main(){
   int n, a = 0;
   scanf("%d", &n);
   if(n%2){
      for(int i = 3; i*i <= n; i+=2)
         if(n%i == 0) {a = n-(n/i); break;}
      if(a == 0) a = n-1;
   }else {a = n-n/2;}
   printf("%d", a);
}