#include <cstdio>
int inf = 1000001;
int main(){
    int n, k, cnt = 0, c[101], dp[10001];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &c[cnt]);
        if(c[cnt] <= k) cnt++;
    }
    dp[0] = 0;
    for(int i = 1; i <= k; i++) dp[i] = inf;
    for(int i = 0; i < cnt; i++){
        for(int j = c[i]; j <= k; j++){
            dp[j] = dp[j] < dp[j-c[i]]+1?dp[j]:dp[j-c[i]]+1;
        }
    }
    if(dp[k] == inf) dp[k] = -1;
    printf("%d\n", dp[k]);
}