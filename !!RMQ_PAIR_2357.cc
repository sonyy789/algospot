#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr;
vector<pair<int, int>> tree;
int min(int a, int b) {return a<b? a:b;}
int max(int a, int b) {return a>b? a:b;}
int inf = 2e9;
pair<int,  int> rmq(int l, int r, int a, int b, int node){
    if(r < a || b < l) return make_pair(inf, -1);
    if(a <= l && r <= b) return tree[node];
    int mid = l+(r-l)/2;
    pair<int, int> ret1 = rmq(l, mid, a, b, node*2);
    pair<int, int> ret2 = rmq(mid+1, r, a, b, node*2+1);
    ret1.first = min(ret1.first, ret2.first);
    ret1.second = max(ret1.second, ret2.second);
    return ret1;
}
pair<int, int> init(int l, int r, int node){
    if(l == r) return tree[node] = make_pair(arr[l], arr[l]);
    int mid = l + (r-l)/2;
    pair<int, int> temp = init(l, mid, node*2);
    tree[node] = init(mid+1, r, node*2+1);
    tree[node].first = min(tree[node].first, temp.first);
    tree[node].second = max(tree[node].second, temp.second);
    return tree[node];
} 
int main(){
    int a, b, n, m;
    scanf("%d%d", &n, &m);
    int h = ceil(log2(n));
    arr = vector<int>(n, 0);
    tree = vector<pair<int, int>>((1<<(h+1))+1, make_pair(inf, -1)); // min,max
    pair<int, int> ans;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    init(0, n-1, 1);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        ans = rmq(0, n-1, a-1, b-1, 1);
        printf("%d %d\n", ans.first, ans.second);
    }
    
}