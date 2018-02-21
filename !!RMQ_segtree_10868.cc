#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int inf = 2e9;
vector<int> arr, tree;
int min(int a, int b){return a<b? a:b;}
int init(int l, int r, int node){
    if(l == r) return tree[node] = arr[l];
    int mid = l+(r-l)/2;
    return tree[node] = min(init(l, mid, node*2), init(mid+1, r, node*2+1));
}
int rmq(int l, int r, int a, int b, int node){
    if(b < l || r < a) return inf;
    if(a <= l && r <= b) return tree[node];
    int mid = l+(r-l)/2;
    return min(rmq(l, mid, a, min(mid, b), node*2), rmq(mid+1, r, -min(-mid, -a), b, node*2+1));
}
int main(){
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    arr = vector<int>(n);
    int size = ceil(log2(n)); 
    tree = vector<int>(1 <<(size+1), inf);  /// rmq nearest 2^N & *2
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    init(0, n-1, 1);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a,&b);
        printf("%d\n", rmq(0, n-1, a-1, b-1, 1));
    }
}