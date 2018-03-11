#include <cstdio>
int n, arr[50], ans[7];
void perm(int depth, int idx){
	if((6-depth) > (n-idx)) return;
	if(depth == 6){
		for(int i = 0; i < 6; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for(int i = idx; i < n; i++){
			ans[depth] = arr[i];
			perm(depth+1, i+1);
	}
}
int main(){
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		perm(0, 0);
		printf("\n");
	}
}