#include <cstdio>
int dp[34];
int main(){
    int n;
    scanf("%d", &n);
    dp[2] = 3; 
    for(int i = 4; i <= n; i+=2){
        dp[i] += (dp[i-2]*3 + 2);
        for(int j = i-4; j > 1; j-=2)
            dp[i] += dp[j]*2;
    }
    printf("%d\n", dp[n]);
}
