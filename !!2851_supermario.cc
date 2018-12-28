#include <cstdio>
int main(){
    int i, a, b, s = 0, f = 1;
    for(i = 0; i < 10; i++){
        scanf("%d", &a);
        b = s+a-100;
        if((b <= 0 || b <= 100-s)&&f) s += a;
        else f = 0;
    }
    printf("%d", s);
}