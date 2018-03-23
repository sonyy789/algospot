#include <cstdio>
#include <cmath>
#define MIN(a,b) a<b?a:b
#define INF 100001
using namespace std;
int n, k, ans;
void dfs(int idx, int cost){
    ans = MIN(ans, cost+abs(idx-n));
    if(idx <= n) return;
    if(idx%2 == 0){
        dfs(idx/2, cost+1);
    }else{
        if(idx > 1) dfs(idx+1, cost+1);
        dfs(idx-1, cost+1);
    }
}
int main(){
    scanf("%d %d", &n, &k);
    ans = abs(n-k); dfs(k, 0);
    printf("%d\n", ans);
}