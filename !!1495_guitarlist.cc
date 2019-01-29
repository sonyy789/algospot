#include <cstdio>
using namespace std;

int n, s, m, i, j, val, ans = -1;
bool dp[101][1001];

int main(){
    scanf("%d%d%d",&n,&s,&m);
    dp[0][s] = true;
    for(i = 1; i <= n; i++){
        scanf("%d", &val);
        for(j = 0; j <= m; j++){
            if(dp[i-1][j]){
                if(j+val <= m) dp[i][j+val] = true;
                if(j-val >= 0) dp[i][j-val] = true;
            }
        }
    }
    for(j = m; j >= 0; j--)
        if(dp[n][j]) {ans = j; break;}
    printf("%d", ans);
}