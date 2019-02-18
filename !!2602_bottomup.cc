#include <cstdio>
#include <cstring>
using namespace std;
char route[22], rock[2][103];
int route_len, rock_len;
int dp[2][102][22];
int main(){
    int i, j, k, l;
    scanf("%s%s%s",route+1, rock[0]+1, rock[1]+1);    
    route_len = strlen(route+1);
    rock_len = strlen(rock[0]+1);
    // set len 1
    for(i = 0; i < 2; i++)
        for(j = 1; j <= rock_len; j++)
            dp[i][j][1] = (route[1] == rock[i][j]);
    // set over 1
    for(i = 2; i <= route_len; i++)
        for(j = 0; j < 2; j++)
            for(k = 1; k <= rock_len; k++)
                if(route[i] == rock[j][k])
                    for(l = 1; l < k; l++)
                        dp[j][k][i] += dp[!j][l][i-1];
    // search ans
    int ans = 0;
    for(i = 1; i <= rock_len; i++)
        ans += (dp[0][i][route_len]+dp[1][i][route_len]);
    printf("%d", ans);
}