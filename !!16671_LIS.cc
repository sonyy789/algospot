#include <cstdio>
int n, arr[1001], dp[1001], ans = 0;
int solve(int idx){
    if(idx == n) return 0;
    int &ret = dp[idx];
    if(ret) return ret;
    for(int i = idx+1; i < n; i++){
        if(arr[idx] >= arr[i]) continue;
        int temp = solve(i);
        ret = ret > temp? ret:temp;
    }
    return ret = ret+1;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++)
        ans = ans > solve(i)?ans:solve(i);
    printf("%d\n", ans);
}