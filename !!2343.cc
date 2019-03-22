#include <cstdio>
typedef long long int lld;
int n, m;
int A[100001];
lld lo, hi, mid, ans, val;
int main(){
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    lo = 0, hi = (lld)n*1e4;
    while(lo <= hi){
        mid = (lo+hi)>>1;
        i = j = 1;
        for(i; i <= m; i++){
            val = mid;
            for(j; j <= n && val >= A[j]; j++)
                val -= A[j];
        }
        if(i == m+1 && j == n+1){
            ans = mid;
            hi = mid-1;
        }else lo = mid+1;
    }
    printf("%lld", ans);
}