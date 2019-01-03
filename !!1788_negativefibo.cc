#include <cstdio>
int mod = 1e9;
int main(){
    int i, n, A[3] = {0, 1, 1};
    scanf("%d", &n);
    int n2 = n;
    if(n < 0) n2 = -n;
    for(i = 3; i <= n2; i++)
        A[i%3] = (A[(i-1)%3]+A[(i-2)%3])%mod;
    if(n < 0 && n2%2 ==0) printf("-1\n");
    else if(n == 0) printf("0\n");
    else printf("1\n");
    printf("%d\n", A[n2%3]);
}