#include <cstdio>
#include <algorithm>
#define MOD 1000000000
using namespace std;
typedef long long int lld;
int n, i, j, k, a;
lld dp[101][1024][10]; // TOO dulicated!! 1024 can be reduced to 4
                        // dp[101][4][10] / 0 : visited none / 1 : visited 0 / 2 : visited 9 / 3 : visited all
int main(){
    scanf("%d", &n);
    for(i = 1; i < 10; i++)
        dp[1][1<<i][i] = 1;
    for(i = 2; i <= n; i++){
        for(j = 1,a = 2; j < 9; j++, a <<= 1)
            for(k = 0; k < 1024; k++)
                dp[i][k|a][j] = ((lld)dp[i][k|a][j]+dp[i-1][k][j-1]+dp[i-1][k][j+1])%MOD;
        for(k = 0; k < 1024; k++){
            dp[i][k|1][0] = ((lld)dp[i][k|1][0]+dp[i-1][k][1])%MOD;
            dp[i][k|512][9] = ((lld)dp[i][k|512][9]+dp[i-1][k][8])%MOD;
        }
    }
    lld ans = 0;
    for(i = 0; i < 10; i++)
        ans += dp[n][1023][i];
    printf("%lld", ans%MOD);
}


!