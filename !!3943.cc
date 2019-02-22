#include <cstdio>
typedef long long int lld;
int t, n;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        lld ans = 1;
        while(n != 1){
            ans = ans > n ? ans:n;
            if(n&1) n = (n*3)+1;
            else n >>= 1;
        }
        printf("%lld\n", ans);
    }
}