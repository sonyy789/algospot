#include <cstdio>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> tree;
vector<int> mem, visited;
int max(int a, int b){return a>b?a:b;}
int ans = 0;
int dfs(int idx, int sum, int prev){
	int &ret = mem[idx];
	if(ret >= 0) return 0;
	ret = 0;
	int res = 0;
	for(int i = 0; i < tree[idx].size(); i++){
		int next = tree[idx][i].first;
		int leng = tree[idx][i].second;
		res = dfs(next, leng+sum, leng);
		ans = max(ans, ret+res);
		ret = max(ret, res);
	}
	ans = max(ans, sum+ret);
	return ret += prev;
}
int main(){
	int v, idx, a, l;
	scanf("%d", &v);
	tree = vector<vector<pair<int, int>>>(v+1);
	mem = vector<int>(v+1, -1);
	for(int i = 0; i < v; i++){
		scanf("%d", &a);
		while(1){
			scanf("%d", &idx);
			if(idx == -1) break;
			scanf("%d", &l);
			tree[a].push_back(make_pair(idx, l));
		}
	}
	dfs(1, 0, 0);
	printf("%d\n", ans);
}