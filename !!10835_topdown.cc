#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, i, j, ans;
int A[2001], B[2001];
int dp[2002][2002];
int solve(int l, int r){
    if(l == n+1 || r == n+1) return 0;
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    ret = solve(l+1, r); ret = max(ret, solve(l+1, r+1));
    if(A[l] > B[r]) ret = max(ret, solve(l, r+1)+B[r]);
    return ret;
}
int main(){
    scanf("%d", &n);
    memset(&dp, -1, sizeof(dp));
    for(i = 1; i <= n; i++)
        scanf("%d", A+i);
    for(i = 1; i <= n; i++)
        scanf("%d", B+i);
    printf("%d", solve(0, 0));
}