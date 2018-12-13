#include <cstdio>
#include <algorithm>
int ansIdx = 0, A[101], V[101], O[101];
int solve(int idx, int cnt){
   int ret;
   if(V[idx] < 0) return 0;
   else if(V[idx] > 0) return cnt-V[idx];
   else{
      V[idx] = cnt;
      ret = solve(A[idx], cnt+1);
      if(ret > 0) O[ansIdx++] = idx;
   }
   V[idx] = -1;
   return ret-1;
}
int main(){
   int n; scanf("%d", &n);
   for(int i = 1; i <= n; i++)
      scanf("%d", &A[i]), V[i] = 0;
   for(int i = 1; i <= n; i++)
      if(!V[i]) solve(i, 1);
   std::sort(&O[0], &O[ansIdx]);
   printf("%d\n", ansIdx);
   for(int i = 0; i < ansIdx; i++)
      printf("%d\n", O[i]);
}