#include <cstdio>
int min(int a, int b){return a<b? a:b;}
int main()
{
    int t, k, arr[501], dp[501][501];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &k);
        arr[0] = 0;
        for(int i = 1; i <= k; i++)
        {
            scanf("%d", &arr[i]);
            arr[i] += arr[i-1];
            dp[i][i] = 0;
        }
        for(int i = k-1; i >= 1; i--)
            for(int d = 1; i+d <= k; d++)
            {
                int j = i+d;
                dp[i][j] = 2e9;
                for(int m = i; m < j; m++)
                    dp[i][j] = min(dp[i][j], dp[i][m]+dp[m+1][j]);
                dp[i][j] += (arr[j]-arr[i-1]);
            }
        printf("%d\n", dp[1][k]);
    }
}