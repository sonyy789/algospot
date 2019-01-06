#include <cstdio>
int main(){
   int a,b,c,d,e,f,i;
   for(i = 0; i < 3; i++){
      scanf("%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f);
      if(f < c) e--,f=(f+60-c);
      else f-= c;
      if(e < b) d--,e=(e+60-b);
      else e -= b;
      d-=a;
      printf("%d %d %d\n",d,e,f);
   }
}