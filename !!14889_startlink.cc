#include <cstdio>
#include <cmath>
int n, ans = 1e9 ,s[20][20];
int a[10], b[10], idx1 = 0, idx2 = 0;
void solve(int idx){
    if(!ans) return;
    if(idx == n){
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n/2-1; i++)
            for(int j = i+1; j < n/2; j++){
                sum1 += (s[a[i]][a[j]]+s[a[j]][a[i]]);
                sum2 += (s[b[i]][b[j]]+s[b[j]][b[i]]);
            }
        int tmp = std::abs(sum1-sum2);
        ans = ans<tmp?ans:tmp;
        return;
    }
    a[idx1++] = idx;
    if(idx1 <= n/2) solve(idx+1);
    idx1--;
    b[idx2++] = idx;
    if(idx2 <= n/2) solve(idx+1);
    idx2--;
}
int main(){
    scanf("%d", &n);
    int in;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &s[i][j]);
    a[idx1++] = 0;
    solve(1);
    printf("%d\n", ans);
}