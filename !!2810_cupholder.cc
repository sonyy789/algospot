#include <cstdio>
int main(){
   char S[52];
   int n, i = 0, f = 0, a = 0;
   scanf("%d", &n);
   for(scanf("%s",S);S[i];i++){
      if(S[i] == 'L'){
         if(f) a++;
         f = 1; i++;
      }
   }
   printf("%d", i-a);
}