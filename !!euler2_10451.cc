#include <cstdio>
int node[1001];
int dfs(int idx){
	int start = idx;
	int next;
	while(node[idx]){
		next = node[idx];
		node[idx] = 0;
		idx = next;
	}
	return start==idx?1:0;
}
int dfsAll(int n){
	int ret = 0;
	for(int i = 1; i <= n; i++){
		if(node[i]) ret += dfs(i);
	}
	return ret;
}
int main(){
	int t, n, a;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a);
			node[i] = a;
		}
		printf("%d\n",dfsAll(n));
	}
}
