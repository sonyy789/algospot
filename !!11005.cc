#include <cstdio>
int n, b;
long long int a;
int main(){
    a = 1;
    scanf("%d%d", &n, &b);
    while(a*b <= n){ a *= b;}
    while(a){
        int tmp = n/a;
        if(tmp < 10) printf("%d", tmp);
        else printf("%c", tmp+55);
        n %= a; a /= b;
    }
}