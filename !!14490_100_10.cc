#include <cstdio>
int n, m;
int gcd(int a, int b){
    return b==0?a:gcd(b, a%b);
}
int main(){
    scanf("%d:%d",&n,&m);
    int comm = gcd(n,m);
    printf("%d:%d",n/comm,m/comm);
}