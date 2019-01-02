#include <cstdio>
int main(){
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j*j<= i;j++) sum += !(i%j);
    printf("%d", sum);
}