#include <cstdio>
#include <cmath>
#define MOD 1000000007
typedef long long int lld;
int i;
int A[60];
lld a, x;

int main(){
    scanf("%lld%lld", &a, &x);
    if(a == 1){
        printf("1");
        return 0;
    }
    A[0] = a%MOD;
    for(i = 1; ((lld)1<<i)<= x; i++)
        A[i] = ((lld)A[i-1]*A[i-1])%MOD;
    lld ans = 1;
    while(x > 0){
        lld t = (x&-x);
        x -= t;
        ans *= (lld)A[(int)log2(t)];
        ans %= MOD;
    }
    printf("%lld", ans);
}