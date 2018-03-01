#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> arr, tree;
vector<int> nodeIdx;
long long init(int l, int r, int node){
    if(l == r){
        nodeIdx[l] = node;
        return tree[node] = arr[l];
    }
    int mid = l+(r-l)/2;
    tree[node] += init(l, mid, node*2);
    tree[node] += init(mid+1, r, node*2+1);
    return tree[node];
}
long long rsq(int l, int r, int a, int b, int node){
    if(b < l || a > r) return 0;
    if(a <= l && r <= b) return tree[node];
    int mid = l+(r-l)/2;
    long long ret = rsq(l, mid, a, b, node*2);
    return ret += rsq(mid+1, r, a, b, node*2+1);
}
void update(int idx, long long val){
    long long diff = val-arr[idx];
    arr[idx] = val;
    int node = nodeIdx[idx];
    while(node != 0){
        tree[node] += diff;
        node /= 2;
    }
    return;
}
int main(){
    int n, m, k, a;
    long long b, c;
    scanf("%d%d%d", &n, &m, &k);
    m += k;
    arr = vector<long long>(n, 0);
    nodeIdx = vector<int>(n, 0);
    int h = ceil(log2(n));
    tree = vector<long long>((1<<(h+1))+1, 0);
    for(int i = 0; i < n; i++)  
        scanf("%lld", &arr[i]);
    init(0, n-1, 1);
    while(m--){
        scanf("%d%lld%lld", &a, &b, &c);
        if(a == 1) update(b-1, c);
        else printf("%lld\n", rsq(0, n-1, b-1, c-1, 1));
    }
}