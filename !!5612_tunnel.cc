#include <cstdio>
int main(){
   int n, m, a, b, c = 0;
   for(scanf("%d%d",&n,&m); n--;){
      scanf("%d%d",&a,&b);
      m += (a-b);
      if(m < 0) {c = 0; break;}
      c = c > m ? c : m;
   }
   printf("%d", c);
}