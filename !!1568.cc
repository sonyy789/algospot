#include <cstdio>
#define MAX 44720
using namespace std;
int n, i, lo, hi, mid, sub, ans;
int A[MAX+1];
int main(){
    for(i = 1; i <= MAX; i++)
        A[i] = A[i-1]+i;
    scanf("%d", &n);
    while(n){
        lo = 1, hi = MAX;
        while(lo <= hi){
            mid = (lo+hi)>>1;
            if(A[mid] <= n){
                sub = mid;
                lo = mid+1;
            }else hi = mid-1;
        }
        ans += sub;
        n -= A[sub];
    }
    printf("%d", ans);
}