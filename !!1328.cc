#include <cstdio>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long int lld;
int n, l, r, i, j;
lld dp[101][101][101];
int main(){
    scanf("%d%d%d", &n, &l, &r);
    dp[1][1][1] = 1;
    for(int nn = 1; nn < n; nn++){
        for(i = 1; i <= nn; i++){
            for(j = 1; j <= nn && i+j <= nn+1; j++){
                dp[nn+1][i+1][j] = (dp[nn+1][i+1][j]+dp[nn][i][j])%MOD;
                dp[nn+1][i][j+1] = (dp[nn+1][i][j+1]+dp[nn][i][j])%MOD;
                dp[nn+1][i][j] = (dp[nn+1][i][j]+dp[nn][i][j]*(nn-1))%MOD;
            }
        }
    }
    printf("%lld", dp[n][l][r]);
}