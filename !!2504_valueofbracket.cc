#include <cstdio>
#include <cmath>
int main(){
   char S[32], T[32];
   int A[32] = {0,}, i=0, c=0, m;
   for(scanf("%s", S);S[i];i++){
      if(S[i] == '(' || S[i] == '[') T[++c] = S[i];
      else{
         if(!c || std::abs(S[i]-T[c]) > 2) {c=1; break;}
         m = S[i]==']'?3:2;
         if(A[c]) A[c-1] += A[c]*m;
         else A[c-1] += m;
         A[c--] = 0;
      }
   }
   printf("%d", c>0?0:A[0]);
}