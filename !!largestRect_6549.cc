#include <cstdio>
#include <vector>
#include <cmath>
#define MAX 100001
using namespace std;
typedef long long ll;
int inf = 2e9;
int n, arr[MAX];
vector<int> tree;
ll max(ll a, ll b) {return a>b?a:b;}
int init(int l, int r, int node){
	if(l == r) return tree[node] = l;
	int mid = l+(r-l)/2;
	int idx1 = init(l, mid, node*2);
	int idx2 = init(mid+1, r, node*2 +1);
	return tree[node] = arr[idx1]<=arr[idx2]?idx1:idx2;
}
int rmq(int l, int r, int a, int b, int node){
	if(l > b || r < a) return n;
	if(a <= l && r <=b) return tree[node];
	int mid = l+(r-l)/2;
	int ret1 = rmq(l, mid, a, b, node*2);
	int ret2 = rmq(mid+1, r, a, b, node*2+1);
	return arr[ret1]<=arr[ret2]?ret1:ret2;
}
ll solve(int l, int r){
	if(l > r) return -1;
	int idx = rmq(0, n-1, l, r, 1);
	ll res = (r-l+1)*arr[idx];
	ll res2 = max(solve(l, idx-1), solve(idx+1, r));
	return max(res, res2);
}
int main(){
	int h = ceil(log2(MAX));
	tree = vector<int>((1<<(h+1))+1, 0);
	while(1){
		scanf("%d", &n);
		if(n == 0) return 0;
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		arr[n] = inf;
		init(0, n-1, 1);
		printf("%lld\n", solve(0,n-1));
	}
}