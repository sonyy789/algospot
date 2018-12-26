#include <cstdio>
int main(){
	int t, r, e, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &r, &e, &c);
		e -= c;
		if(r < e) printf("advertise\n");
		else if(r > e) printf("do not advertise\n");
		else printf("does not matter\n");
	}
}