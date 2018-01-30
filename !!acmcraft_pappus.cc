#include <cstdio>
#define MAX 1001
int t, n, k, w, A[MAX], dp[MAX];
bool e[MAX][MAX];
int max(int a, int b) {return a>b?a:b;}
int dfs(int curr){
	int &ret = dp[curr];
	if(ret != -1) return ret;
	for(int i = 0; i < n; i++)
		if(e[curr][i]) ret= max(ret, dfs(i));
	if(ret == -1) return ret = A[curr];
	return ret =(ret+A[curr]);
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i = 0; i < n; i++){
			scanf("%d", &A[i]);
			dp[i] = -1;
			for(int j = 0; j < n; j++) e[i][j] = false;
		}
		int a, b;
		for(int i = 0; i < k; i++){
			scanf("%d%d", &a,&b);
			e[--b][--a] = true;
		}
		scanf("%d", &w);
		w--;
		dfs(w);
		printf("%d\n", dp[w]);
	}
}