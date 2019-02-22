#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, i, j, a, curr;
int p_sum[50001], dp[3][50001];
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", p_sum+i);
        p_sum[i] += p_sum[i-1];
    }
    scanf("%d", &k);
    for(i = 1; i <= n; i++){
        a = i-k<0?0:i-k; 
        curr = p_sum[i]-p_sum[a];
        dp[0][i] = max(curr, dp[0][i-1]);
        dp[1][i] = max(curr+dp[0][a], dp[1][i-1]);
        dp[2][i] = max(curr+dp[1][a], dp[2][i-1]);
    }
    printf("%d", dp[2][n]);
}