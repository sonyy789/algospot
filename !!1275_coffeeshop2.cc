#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int lld;
lld tree[262200];
int nodeIdx, size;
void update(int idx, lld diff){
    while(idx > 0){
        tree[idx] += diff;
        idx >>= 1;
    }
}
lld find(int a, int b){
    lld ret = 0;
    while(a <= b){
        if(a&1) ret += tree[a++];
        if(~b&1) ret += tree[b--];
        a>>=1, b>>=1;
    }    
    return ret;
}
int main(){
    int a,b,i,x,y,n,q;
    scanf("%d%d",&n,&q);
    nodeIdx = 1<<((int)ceil(log2(n)));
    size = (nodeIdx<<1)+1;
    nodeIdx--;
    for(i = 1; i <= n; i++){
        scanf("%lld", &val);
        update(nodeIdx+i, val);
    }
    while(q--){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        if(x > y) swap(x,y);
        printf("%lld\n", find(nodeIdx+x,nodeIdx+y));
        update(nodeIdx+a, b-tree[nodeIdx+a]);
    }
}