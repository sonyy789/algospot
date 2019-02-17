#include <cstdio>
#include <algorithm>
using namespace std;
int n, i, j, v, len = 1;
int dp[40001];
int main(){
    scanf("%d", &n);;
    for(i = 1; i <= n; i++){
        scanf("%d", &v);
        auto pos = lower_bound(dp+1, dp+len+1, v);
        *pos = v;
        if(pos == dp+1+len) len++;
    }
    printf("%d", len-1);
}