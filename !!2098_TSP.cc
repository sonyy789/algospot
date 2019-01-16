#include <cstdio>
#include <algorithm>
using namespace std;
int W[16][16], dp[65536][16];
int main(){
    int i,j,n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) 
            scanf("%d", &W[i][j]);
    int last = (1<<n);
    for(int i = 1; i < last; i++)
        for(int j = 0; j < n; j++) dp[i][j] = 1e9;
    dp[1][0] = 0;
    for(int stat = 1; stat < last; stat+=2){
        for(int i = 0; i < n; i++){
            if(dp[stat][i] == 1e9) continue; 
            for(int j = 0, visit = 1; j < n; j++, visit<<=1){
                if(W[i][j] == 0 || (stat&visit)) continue;
                dp[stat|visit][j] = min(dp[stat|visit][j], dp[stat][i]+W[i][j]);
            }
        }
    }
    int ans = 2e9;
    for(int i = 1; i < n; i++){
        if(!W[i][0]) continue;
        ans = min(ans, dp[last-1][i]+W[i][0]);
    }
    printf("%d", ans);
}