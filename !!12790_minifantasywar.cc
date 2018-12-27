#include <cstdio>
int main(){
    int t, a, b, c, d, x, y, w, z;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &x, &y, &w, &z);
        a += x; b += y; c += w; d += z;
        a = a<1 ? 1:a; 
        b = b<1 ? 1:b;
        c = c<0 ? 0:c;
        printf("%d\n",a+5*b+2*(c+d));
    }
}