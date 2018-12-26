#include <cstdio>
int main(){
	long long s, a = 0, b = 0;
	scanf("%lld", &s);
	while(s >= a){ a += ++b;}
	printf("%lld\n", --b);
}