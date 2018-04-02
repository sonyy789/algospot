#include <cstdio>
int main(){
    long long n, zero, one, temp;
    scanf("%lld", &n);
    one = 1; zero = 0;
    for(int i = 1; i < n; i++){
        temp = one;
        one = zero;
        zero += temp;
    }
    printf("%lld\n", zero+one);
}