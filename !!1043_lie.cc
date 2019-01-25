#include <cstdio>
typedef long long int lld;

int i, j, n, m, k, val;
lld is_true = 0;
lld B[51];

int main(){    
    scanf("%d%d%d",&n,&m,&k);
    while(k--){
        scanf("%d", &val);
        is_true |= ((lld)1<<val);
    }
    for(i = 1; i <= m; i++){
        scanf("%d", &k);
        for(j = 1; j <= k; j++){
            scanf("%d", &val);
            B[i] |= ((lld)1<<val);
        }
    }
    for(k = 1; k <= m; k++)
        for(i = 1; i <= m; i++)
            if((is_true&B[i])) is_true |= B[i];
    int ans = 0;
    for(i = 1; i <= m; i++)
        if((is_true&B[i]) ==0) ans++;
    printf("%d", ans);
}