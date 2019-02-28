#include <cstdio>
#include <algorithm>
using namespace std;
int t, n, i;
int H[20001];
int solve(int a, int b){
    if(a == b) return H[a];
    int l, r, m, h, ret;
    m = (a+b)>>1;
    ret = max(solve(a, m), solve(m+1, b));
    l = r = m; h = H[l];
    while(l != a || r != b){
        if(r == b)  h = min(h, H[--l]);
        else if(l == a) h = min(h, H[++r]);
        else if(H[l-1] < H[r+1]) h = min(h, H[++r]);
        else h = min(h, H[--l]);
        ret = max(ret, h*(r-l+1));
    }
    return ret;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            scanf("%d", H+i);
        printf("%d\n", solve(1, n));
    }
}