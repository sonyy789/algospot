#include <cstdio>
#include <algorithm>
using namespace std;

int n, c, i, j, ans;
int A[200001];
bool solve(int len){
    int tmp = c-1;
    int pos = 1;
    for(i = 2; i <= n; i++){
        if(A[i]-A[pos] >= len) tmp--, pos= i;
        if(tmp == 0) return true;
    }
    return false;
}
int main(){
    scanf("%d%d", &n, &c);
    for(i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    sort(&A[1], &A[n+1]);
    int lo = 1, hi = 1e9;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(solve(mid)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d", ans);
}