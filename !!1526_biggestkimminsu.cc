#include <cstdio>
int main(){
    int n, a = 1, f = 0;
    scanf("%d", &n);
    while(1){
        if(n/a < 10) break;
        a *= 10;
    }
    int ans = 0;
    while(a){
        int c = 7*a;
        int d = 4*a/10;
        int e = 4*a;
        if(c+d+ans <= n) ans += c;
        else if(d+e+ans<= n) ans += e;
        a/=10;
    }
    printf("%d", ans);
}