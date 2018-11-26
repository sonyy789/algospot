#include <cstdio>
int main(){
    int n, ans = -1; 
    int arr[1001], dp[1001];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) dp[i] = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        dp[i] += arr[i];
        for(int j = i+1; j < n; j++)
            if(arr[i] < arr[j])
                dp[j] = dp[j]>dp[i]?dp[j]:dp[i];
    }
    for(int i = 0; i < n; i++)
        ans = ans>dp[i]?ans:dp[i];
    printf("%d\n", ans);
}