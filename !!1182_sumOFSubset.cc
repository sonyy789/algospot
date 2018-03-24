#include <cstdio>
int n, s, arr[21];
int solve(int idx, int sum){
    if(idx == n){
        if(sum == 0) return 1;
        return 0;
    }
    int ret = 0;
    ret += solve(idx+1, sum);
    ret += solve(idx+1, sum-arr[idx]);
    return ret;
}
int main(){
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int ans = solve(0, s);
    if(s == 0) ans--;
    printf("%d\n", ans);
}