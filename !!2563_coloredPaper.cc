#include <cstdio>
int main(){
	int A[101][101] = {0,};
	int n, x, y, i, j, a = 0;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &x, &y);
		for(i = y; i < y+10; i++)
			for(j = x; j < x+10; j++){
				if(A[i][j]) continue;
				A[i][j] = 1; a++;
			}
	}
	printf("%d", a);
}