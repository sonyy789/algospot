#include <cstdio>
int arr[15], dp[15];
int min(int a, int b) {return a<b?a:b;}
int main(){
    int t, d, m, m3, y, in;
    scanf("%d", &t);
    for(int z = 1; z <= t; z++){
        scanf("%d %d %d %d",&d,&m,&m3,&y);
        for(int i = 1; i <= 12; i++){
            scanf("%d", &arr[i]), dp[i] = 0;
            dp[i] = dp[i-1]+arr[i]*d;
        }
        for(int i = 1; i <= 12; i++){
            if(arr[i]==0) {dp[i] = dp[i-1]; continue;}
            dp[i] = min(dp[i], dp[i-1]+arr[i]*d);
            dp[i] = min(dp[i], dp[i-1]+m);
            if(i-3 >= 0) dp[i] = min(dp[i], dp[i-3]+m3);
        }
        // for 1 year
        dp[12] = min(dp[12], y+dp[0]);
        printf("#%d %d\n", z, dp[12]);
    }
}