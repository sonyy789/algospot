#include <cstdio>
int len, i, j, a;
char str[1002];
bool dp[1001][1001];
int main(){
    scanf("%s", str+1);
    for(;str[++i] != '\0';) dp[i][i] = true, dp[i][i+1] = (str[i]==str[i+1]);
    a = len = i-1;
    for(i = 2; i < len; i++)
        for(j = 1; i+j <= len; j++)
            dp[j][i+j] = dp[j+1][i+j-1]&(str[j]==str[i+j]);
    for(i = 1; i <= len; i++)
        if(dp[i][len]) {a = i-1; break;}
    printf("%d", len+a);
}