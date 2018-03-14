#include <cstdio>
#include <cmath>
#define MAX 100001
int arr[MAX];
int mem[262145];
int init(int l, int r, int node){
	if(l==r) return mem[node] = arr[l];
	int mid = l+(r-l)/2;
	mem[node] += init(l, mid, node*2);
	mem[node] += init(mid+1, r, node*2+1);
	return mem[node];
}
int find(int l, int r, int a, int b, int node){
	if(r < a || l > b) return 0;
	if(a <= l && r <= b) return mem[node];
	int ret = 0;
	int mid = l + (r-l)/2;
	ret = find(l, mid, a, b, node*2);
	ret += find(mid+1,r,a,b,node*2+1);
	return ret;
}
int main(){
	int n, m, a, b, h;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	init(1, n, 1);
	while(m--){
		scanf("%d%d", &a,&b);
		printf("%d\n", find(1, n, a, b, 1));
	}
}