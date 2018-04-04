#include <cstdio>
int n, i, A[10], tmp, ans = 1, mod = 10007;
int main(){
    A[9] = 1;
    scanf("%d", &n);
    while(n--){
        int psum = 0;
        for(i = 1; i < 10; i++) {psum += A[i];}
        for(i = 1; i < 10; i++){
            tmp = A[i];
            A[i] = psum%mod; ans = (ans+A[i])%mod;
            psum -= tmp;
        }
    }
    printf("%d\n", ans);
}