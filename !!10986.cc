#include <cstdio>
typedef long long int lld;
int n, m;
int A[1000001];
lld C[1001];
int main(){
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", &A[i]);
        C[A[i] = (A[i]+A[i-1])%m]++;
    }
    lld ans = C[0];
    for(i = 0; i < m; i++)
        if(C[i] > 1) ans += (C[i]*(C[i]-1))>>1;
    printf("%lld", ans);
}