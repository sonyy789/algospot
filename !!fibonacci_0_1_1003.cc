#include <cstdio>
int main(){
	int arr[41][2], t, n;
	arr[0][1] = arr[1][0] = 0;
	arr[0][0] = arr[1][1] = 1;
	for(int i = 2; i < 41; i++){
		arr[i][0] = arr[i-1][0]+arr[i-2][0];
		arr[i][1] = arr[i-1][1]+arr[i-2][1];
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d %d\n", arr[n][0], arr[n][1]);
	}
}