#include <cstdio>
int main(){
	int n, a = 0, b, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &b);
		a += b;
	}
	if(a > n/2) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
}
