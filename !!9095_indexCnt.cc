#include <cstdio>
int dp[11];
void solve(int sum){
    if(sum > 10) return;
    dp[sum]++;
    for(int i = 1; i <= 3; i++)
        solve(sum+i);
}
int main(){
    int t, n;
    scanf("%d", &t);
    solve(0);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}