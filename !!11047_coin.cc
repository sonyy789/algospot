#include <cstdio>
int coin[11];
int n, k, i, j, ans;
int main(){
    scanf("%d%d",&n,&k);
    for(i = 1; i <= n; i++)
        scanf("%d", &coin[i]);
    for(i = n; i >= 1; i--){
        int cnt = k/coin[i];
        if(cnt) ans += cnt, k %= coin[i];
    }
    printf("%d", ans);
}