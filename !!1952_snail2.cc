#include <cstdio>
int main(){
   int A[2], i, s, a = 0;
   scanf("%d%d", &A[0], &A[1]);
   s = (A[0]--)*A[1];
   while(s){
      for(i = 1; i >= 0; i--){
         s -= A[i]--;
         if(s == 0) break;
         a++;
      }
   }
   printf("%d", a);
}