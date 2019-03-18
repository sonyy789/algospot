#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, k;
int dp[1000001][11];
int solve(int num, int depth){
    if((num/m) == 0) return -1; // first-zero
    if(depth == k) return num; 
    int &ret = dp[num][depth];
    if(ret != -1) return ret;
    int i, j, a, b;
    for(i = 1; i < m; i *=10)
        for(j = i*10; j <= m; j *= 10){
            a = (num%(j*10))/j;
            b = (num%(i*10))/i;
            ret = max(ret, solve(num-a*j-b*i+a*i+b*j, depth+1));
        }
    return ret;
}
int main(){
    memset(&dp, -1, sizeof(dp));
    scanf("%d%d",&n,&k);
    m = 1;
    while((n/m) >= 10) {m *= 10;}
    printf("%d", solve(n, 0));
}