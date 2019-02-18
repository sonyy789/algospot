#include <cstdio>
#include <cstring>
using namespace std;
char route[22], rock[2][103];
int route_len, rock_len;
int dp[2][102][22];
int solve(int f, int idx, int len){
    if(len > route_len) return 1;
    
    int i, &ret = dp[f][idx][len];
    if(ret) return ret;
    for(i = idx; i <= rock_len; i++)
        if(rock[f][i] == route[len]) ret += solve(!f, i+1, len+1);
    return ret;
}
int main(){
    scanf("%s%s%s",route+1, rock[0]+1, rock[1]+1);    
    route_len = strlen(route+1);
    rock_len = strlen(rock[0]+1);
    printf("%d", solve(0, 1, 1)+solve(1, 1, 1));
}