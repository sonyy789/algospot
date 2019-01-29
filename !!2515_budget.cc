#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n, m, i, ans;
int A[10001];
int solve(int limit){
    int ret = 0, tmp = m;
    for(i = 1; i <= n; i++){
        int val = min(limit, A[i]);
        ret = max(val, ret);
        tmp -= val;
        if(tmp < 0) return 0;
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    scanf("%d", &m);
    sort(&A[1], &A[n+1], greater<int>());
    int lo = 1, hi = 1e5;    
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(solve(mid)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d",solve(ans));
}