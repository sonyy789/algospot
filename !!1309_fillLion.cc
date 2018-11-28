#include <cstdio>
#define MOD 9901
int main(){
    int n, o, x, t;
    scanf("%d", &n);
    o = 2; x = 1;
    while(--n){
        t = x;
        x = (x+o)%MOD;
        o = (o+2*t)%MOD;
    }
    printf("%d\n", (o+x)%MOD);
}