#include <cstdio>
#include <cmath>
int main(){
    int l, c, d;
    float a, b;
    scanf("%d%f%f%d%d", &l, &a, &b, &c, &d);
    c = (int)ceil(a/c); d = (int)ceil(b/d);
    l -= (c>d?c:d);
    printf("%d\n", l);
}