#include <cstdio>
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", ((1<<n)+1)*((1<<n)+1));
}