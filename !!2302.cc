#include <cstdio>
int n, m, a, i;
int dp[41];
bool stat[41];
int main(){
   scanf("%d%d", &n, &m);
   while(m--){
       scanf("%d", &a);
       stat[a] = true;
   }
   dp[0] = dp[1] = 1;
   for(i = 2; i <= n; i++)
       dp[i] = (stat[i]|stat[i-1])?dp[i-1]:dp[i-2]+dp[i-1];
   printf("%d", dp[n]);
}