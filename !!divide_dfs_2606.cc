#include <cstdio>
#include <vector>
using namespace std;
vector<int> edge[101];
bool visit[101];
int dfs(int idx){
	visit[idx] = true;
	int ret = 1;
	for(int i = 0; i < edge[idx].size(); i++){
		int next = edge[idx][i];
		if(!visit[next]) ret += dfs(next);
	}
	return ret;
}
int main(){
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	printf("%d\n", dfs(1)-1);
}