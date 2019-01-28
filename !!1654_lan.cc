#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int k, n, ans,lo, hi, mid;
int L[10005];
bool is_n(int len){
    int i, cnt = 0;
    for(i = 1; i <= k; i++){
        cnt += (L[i]/len);
        if(cnt >= n) return true;
    }
    return false;
}
int main(){
    int i;
    scanf("%d%d", &k, &n);
    for(i = 1; i <= k; i++)
        scanf("%d", &L[i]);
        
    sort(&L[1], &L[k+1], greater<int>());
    lo = 1;
    hi = L[1];
    while(lo <= hi){
        mid = lo+(hi-lo)/2;
        if(is_n(mid)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d", ans);
}