#include <cstdio>
#include <algorithm>
using namespace std;
int n, ans;
int S[9], W[9];
void solve(int curr, int rest){
    int i;
    ans = max(ans, n-rest);
    if(curr == n+1) return;
    if(S[curr] <= 0) solve(curr+1, rest);
    else{
        for(i = 1; i <= n; i++){
            if(i == curr || S[i] <= 0) continue;
            S[curr] -= W[i] , S[i] -= W[curr];
            solve(curr+1, rest-(S[i]<=0)-(S[curr]<=0));
            S[curr] += W[i] , S[i] += W[curr];
        }
    }
}
int main(){
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d%d", &S[i], &W[i]);
    solve(1, n);
    printf("%d", ans);
}