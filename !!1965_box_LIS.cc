#include <cstdio>
#include <cstring>
int main(){
    int i, j, n, temp, ans = 0; 
    int arr[1001], dp[1001] = {0,};
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(arr[i] < arr[j] && dp[i] >= dp[j])
                dp[j] = dp[i]+1;
    for(i = 0; i < n; i++)
        ans = ans > dp[i] ? ans:dp[i];
    printf("%d\n", ans+1);
}