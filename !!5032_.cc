#include <cstdio>
int main(){
    int e, f, c, a = 0;
    scanf("%d%d%d", &e, &f, &c);
    e += f;
    while(e >= c){
        int tmp = e/c;
        a += tmp;
        e = (e%c)+tmp;
    }
    printf("%d", a);
}