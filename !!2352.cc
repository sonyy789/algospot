#include <cstdio>
#include <algorithm>
using namespace std;
int n, nn, i, j, v, ans;
int tree[131080];
int search(int a, int b){
    int ret = 0;
    a += nn, b += nn;
    while(a <= b){
        if(a & 1) ret = max(ret, tree[a++]);
        if(~b & 1) ret = max(ret, tree[b--]);
        a >>= 1, b >>= 1;
    }
    return ret;
}
void update(int idx, int val){
    idx += nn;
    tree[idx] = val;
    while(1){
        idx >>= 1;
        if(idx == 0) return;
        tree[idx] = max(tree[idx<<1], tree[(idx<<1)+1]);
    }
}
int main(){
    scanf("%d", &n);
    for(nn = 1; nn < n; nn <<= 1);
    nn--;
    for(i = 1; i <= n; i++){
        scanf("%d", &v);
        int res = search(1, v-1)+1;
        ans = max(ans, res);
        update(v, res);
    }
    printf("%d", ans);
}