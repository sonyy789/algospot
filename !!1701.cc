#include <cstdio>
#include <cstring>
using namespace std;
int i, j, k, len, ans;
int dp[5001];
char str[5002];
int main(){
    scanf("%s", str+1);
    len = strlen(str+1);
    for(i = 1; i < len; i++){
        memset(dp, 0, sizeof(dp));
        k = 0;
        for(j = i; j < len; j++){
            while(k && str[j+1] != str[k+i]){ k = dp[k+i-1];}
            if(str[j+1] == str[k+i])
                dp[j+1] = ++k;
        }
        for(j = 1; j <= len; j++)
            if(ans < dp[j]) ans = dp[j];
    }
    printf("%d", ans);
}