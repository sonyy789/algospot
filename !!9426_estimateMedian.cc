#include <cstdio>
#include <cmath>
using namespace std;

int tree[131080], A[250001];
int n, k, i, j, mid, size, node_idx;
long long int ans;

void update(int idx, int diff){
    while(idx > 0){
        tree[idx] += diff;
        idx >>= 1;
    }
}
int find_kth(int idx, int k){
    if(idx >= node_idx)
        return idx-node_idx; 
    if(k <= tree[idx*2])
        return find_kth(idx*2,k);
    else
        return find_kth(idx*2+1, k-=tree[idx*2]);
}
int main(){
    scanf("%d%d", &n, &k);
    mid = (k+1)/2;
    node_idx = 1<<((int)ceil(log2(65536)));
    size = (node_idx<<1)+1;
    for(i = 1; i <= k; i++){
        scanf("%d", &A[i]);
        update(node_idx+A[i], 1);
    }
    ans += find_kth(1, mid);
    for(i = k+1; i <= n; i++){  
        update(node_idx+A[i-k], -1);
        scanf("%d", &A[i]);
        update(node_idx+A[i], 1);
        int ret = find_kth(1, mid);
        ans += find_kth(1, mid);
    }
    printf("%lld", ans);
}