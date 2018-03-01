#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> edge;
vector<int> arr, visited;
void solve(int idx, int parent){
	visited[idx] = parent;
	for(int i = 0; i < edge[idx].size(); i++){
		int next = edge[idx][i];
		if(visited[next] == 0)
			solve(next,idx);
	}
}
int main(){
	int n, a, b;
	scanf("%d", &n);
	edge = vector<vector<int>>(n+1);
	arr = vector<int>(n+1);
	visited = vector<int>(n+1, 0);
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	solve(1, 1);
	for(int i = 2; i <=n; i++)
		printf("%d\n", visited[i]);
}