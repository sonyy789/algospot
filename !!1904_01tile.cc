#include <cstdio>
int main(){
    int n, a = 0, b = 1, c;
    scanf("%d", &n);
    while(n--){
        c = a+b;
        c = c>=15746 ? c-15746:c;
        a = b; b = c;
    }
    printf("%d\n", c);
}