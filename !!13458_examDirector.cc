#include <cstdio>
#include <cmath>
int A[1000001];
int main(){
    int n, b, c;
    scanf("%d", &n);
    for(int i =0; i < n; i++)  scanf("%d", &A[i]);
    scanf("%d %d", &b, &c);
    long long ans = n;
    for(int i =0; i < n; i++){
        float tmp = A[i]-b;
        if(tmp <= 0) continue;
        ans += ceil(tmp/c);
    }
    printf("%lld\n", ans);
}