#include <cstdio>
int main(){
    int i, j, n, ans = 0, A[1001], dp[2][1001];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        dp[0][i] = 0;
        for(j = 0; j < i; j++)
            if(A[i]>A[j] && dp[0][i] <= dp[0][j])
                dp[0][i] = dp[0][j]+1;
    }
    for(i = n-1; i >=0; i--){
        dp[1][i] = 0;
        for(j = n-1; j > i; j--)
            if(A[i]>A[j] && dp[1][i] <= dp[1][j])
                dp[1][i] = dp[1][j]+1;
        ans = ans > (dp[0][i]+dp[1][i])?ans:(dp[0][i]+dp[1][i]);
    }
    printf("%d\n", ans+1);        
}