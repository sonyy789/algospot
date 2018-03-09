#include <cstdio>
#include <algorithm>
int ans[25*25];
bool arr[27][27];
int find(int y, int x){
	if(!arr[y][x]) return 0;
	int ret = 1;
	arr[y][x] = false;
	ret += find(y-1, x);
	ret += find(y, x-1); 
	ret += find(y+1, x);
	ret += find(y, x+1); 
	return ret;
}
int findAll(int n){
	int idx = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <=n; j++)
			if(arr[i][j])
				ans[idx++] = find(i,j);
	return idx;
}
int main(){
	int n;
	char s[26];
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for(int j = 1; j <=n; j++)
			if(s[j-1] == '1')
				arr[i][j] = true;
	}
			
	int res = findAll(n);
	printf("%d\n", res);
	std::sort(&ans[0], &ans[res]);
	for(int i = 0; i < res; i++)
		printf("%d\n", ans[i]);
}