#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a_len, b_len;
int dp[1001][1001];
char a[1002], b[1002];
int solve(int a_idx, int b_idx){
    if(a_idx == a_len) return b_len-b_idx;
    if(b_idx == b_len) return a_len-a_idx;
    int &ret = dp[a_idx][b_idx];
    if(ret) return ret;
    if(a[a_idx] == b[b_idx]) return ret = solve(a_idx+1, b_idx+1);
    int c, d, e;
    c = solve(a_idx+1, b_idx);
    d = solve(a_idx+1, b_idx+1);
    e = solve(a_idx, b_idx+1);
    return ret = min(c, min(d, e))+1;
}
int main(){
    scanf("%s%s", a, b);
    a_len = strlen(a); b_len = strlen(b);
    printf("%d", solve(0, 0));
}