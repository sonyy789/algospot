#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int>> tree[10001];
vector<int> v;
int ans = 0;
int max(int a, int b){return a>b?a:b;}
int dfs(int idx, int prev){
	int &ret = v[idx];
	if(ret >= 0) return 0;
	ret = 0;
	int res = 0;
	for(int i = 0; i < tree[idx].size(); i++){
		int next = tree[idx][i].first;
		res = dfs(next, tree[idx][i].second);
		ans = max(ans, ret+res);
		ret = max(ret, res);
	}
	return v[idx] = prev+ret;
}
int main(){
	int n, a, b, c;
	scanf("%d", &n);
	v = vector<int>(n+1, -1);
	for(int i = 0; i < n-1; i++){
		scanf("%d%d%d", &a, &b, &c);
		tree[a].push_back(make_pair(b,c));
	}
	dfs(1, 0);
	printf("%d\n", ans);
}