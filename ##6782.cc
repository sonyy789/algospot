#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int lld;
int t, z, idx;
lld n, ans;
lld A[1000002];
int main(){
    int i, j;
    for(lld a = 1; a*a <= 1e12; a++)
        A[++idx] = a*a;
    scanf("%d", &t);
    for(z = 1; z <= t; z++){
        scanf("%lld", &n);
        ans = 0;
        while(n != 2){
            double d = sqrt(n);
            if(d == (int)d) n = sqrt(n), ans++;
            else{
                int lo = 1, hi = idx, mid, t_idx;
                while(lo <= hi){
                    mid = (lo+hi)>>1;
                    if(n <= A[mid]) hi = mid-1, t_idx = mid;
                    else lo = mid+1;
                }
                ans += (A[mid]-n);
                n = A[mid];
            }
        }
        printf("#%d %lld\n", z, ans);
    }
}