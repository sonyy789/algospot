#include <cstdio>
int t, n, p, q, i;
long long int ans;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld%d", &ans, &n);
        for(i = 1; i <= n; i++){
            scanf("%d%d",&q,&p);
            ans += p*q;
        }
        printf("%lld\n", ans);
    }
}