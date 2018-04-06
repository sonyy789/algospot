#include <cstdio>
int n, psum, dp[34] = {1};
int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i+=2){
        /// changing part : use principle >> newPattern always 2
        /// psum : All summation of prev value under N-4
        dp[i] = dp[i-2]*3+psum*2;
        psum = dp[i-2];
    }
    printf("%d\n", dp[n]);
}
