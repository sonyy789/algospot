#include <cstdio>
int n, jump[100][100];
long long cost[100][100];
long long dfs(int y, int x){
	if(y >= n || x >= n) return 0;
	else if(y == n-1 && x == n-1) return 1;
	long long &ret = cost[y][x];
	if(ret > 0 || jump[y][x] == 0) return ret;
	ret += dfs(y+jump[y][x], x);
	ret += dfs(y, x+jump[y][x]);
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)	
			scanf("%d", &jump[i][j]);
	printf("%lld", dfs(0,0));
}