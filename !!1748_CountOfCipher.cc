#include <cstdio>
int main(){
    int n, add, ans, c;
    add = 1; ans = 0; c = 10;
    scanf("%d", &n);
    while(c <= n){
        ans+=(c-(c/10))*add;
        add++; c *= 10;
    }
    printf("%d\n", ans+(n-c/10+1)*add);
}