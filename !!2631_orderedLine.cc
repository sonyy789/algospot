#include <cstdio>
int main(){
   int n, res = 0, A[201], dp[201];
   scanf("%d", &n);
   for(int i = 0; i < n; i++){
       dp[i] = 1;
       scanf("%d", &A[i]);
       for(int j = 0; j < i; j++){
           if(A[i] > A[j] && dp[i] <= dp[j]){
               dp[i] = dp[j]+1;
           }
       }
       res = res > dp[i] ? res:dp[i];
   }
   printf("%d\n", n-res);
}