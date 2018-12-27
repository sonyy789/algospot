#include <cstdio>
int main(){
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    a = a*e; e -= c;
    if(e > 0) b += e*d;
    a = a < b ? a:b;
    printf("%d", a);
}