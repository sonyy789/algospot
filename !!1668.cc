#include <cstdio>
typedef long long int lld;
lld H[51];
int solve(int idx, int dir){
    int i, h = 0, cnt = 0;
    for(i = idx; H[i] != 0; i+=dir)
        if(H[i] > h){ cnt++; h = H[i];}
    return cnt;
}
int main(){
    int i, n;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%lld", H+i);
    printf("%d\n%d", solve(1,1), solve(n,-1));
}