#include <cstdio>
int t, n, m, dp[31][31];
int solve(int l, int r){
    int &ret= dp[l][r];
    if(ret) return ret;
    if(l == r) {return 1;}
    if(l == 1) {return r;}
    for(int i = 1; i <= r-l+1; i++){
        ret += solve(l-1, r-i);
    }
    return ret;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        printf("%d\n", solve(n,m));
    }
}