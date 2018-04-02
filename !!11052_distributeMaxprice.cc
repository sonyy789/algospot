#include <cstdio>
int dp[1001][1001], val[1001];
int max(int a, int b) {return a>b?a:b;}
int solve(int idx, int n){
    if(n == 0) return 0;
    if(idx == 1) return val[1]*n;
    int &ret = dp[idx][n];
    if(ret) return ret;
    for(int i = 0; i*idx <= n; i++)
        ret = max(ret, val[idx]*i+solve(idx-1,n-i*idx));
    return ret;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
    printf("%d\n", solve(n, n));
}