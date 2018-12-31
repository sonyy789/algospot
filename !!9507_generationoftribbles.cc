#include <cstdio>
int main(){
    int t, n;
    long long A[70], sum;
    A[0] = A[1] = 1; A[2] = 2; A[3] = 4; sum = 8;
    for(int i = 4; i <= 67; i++){
        A[i] = sum;
        sum = sum+A[i]-A[i-4];
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", A[n]);
    }
}