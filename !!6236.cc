#include <cstdio>
using namespace std;
int i, j, n, m;
int lo, hi, mid, ans;
int A[100001];
bool chk(int add){
    int tmp_m = m, cash = 0;
    for(i = 1; i <= n; i++){
        if(cash < A[i]){
            cash = add-A[i];
            tmp_m--;
            if(cash < 0 || tmp_m < 0) break;
        }else cash -= A[i];
    }
    return i==n+1?true:false;
}
int main(){
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", A+i);
        hi += A[i];
    }
    lo = 1;
    while(lo <= hi){
        mid = (lo+hi)>>1;
        if(chk(mid)){
            ans = mid;
            hi = mid-1;
        }else lo = mid+1;    
    }
    printf("%d", ans);
}