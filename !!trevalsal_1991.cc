#include <cstdio>
#include <cstring>
int arr[26], tree[26][2];
void solve(int idx, int f){
	if(f == 0) printf("%c", idx+'A');
	if(tree[idx][0] >= 0) solve(tree[idx][0], f);
	if(f == 1) printf("%c", idx+'A');
	if(tree[idx][1] >= 0) solve(tree[idx][1], f);
	if(f == 2) printf("%c", idx+'A');
}
int main(){
	int n, ia, ib, ic;
	scanf("%d", &n);
	getchar();
	char s[6];
	for(int i = 0; i < n; i++){
		scanf("%[^\n]s", s);
		ia = s[0]-'A', ib = s[2]-'A', ic = s[4]-'A';
		tree[ia][0] = ib;
		tree[ia][1] = ic;
		getchar();
	}
	for(int i = 0; i < 3; i++)
		solve(0, i), printf("\n");
}