#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, w;
int W[101], N[101], I[101];
int dp[1001][102];
char name[101][22];
int main(){
    int i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &w);
        for(i = 0; i < n; i++)
            scanf("%s%d%d", name[i], &W[i], &N[i]);
        memset(&dp, -1, sizeof(dp));
        dp[0][0] = 0; 
        for(i = 0; i < n; i++){
            for(j = 0; j <= w; j++)
                if(dp[j][i] != -1){
                    dp[j][i+1] = max(dp[j][i+1], dp[j][i]);
                    if(j+W[i] <= w) dp[j+W[i]][i+1] = max(dp[j+W[i]][i+1], dp[j][i]+N[i]);
                }
        }
        int tmp_w, val = 0, size = 0;
        for(i = 0; i <= w; i++){
            if(val < dp[i][n]){
                val = dp[i][n];
                tmp_w = i;
            }
        }
        while(n){
            if(dp[tmp_w][n] != dp[tmp_w][n-1]){
                I[size++] = n-1;
                tmp_w -= W[n-1];
            }
            n--;
        }
        printf("%d %d\n", val, size);
        sort(I, I+size);;
        for(i = 0; i < size; i++)
            printf("%s\n", name[I[i]]);
        
    }
}