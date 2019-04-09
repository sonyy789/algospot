#include <cstdio>
#include <unordered_map>
typedef long long int lld;
using namespace std;
int p, q;
lld n;
unordered_map<lld, lld> um;
lld solve(lld val){
    if(um[val]) return um[val];
    if(val == 0) return 1;
    return um[val] = solve(val/p)+solve(val/q);
}
int main(){
    int i, j;
    scanf("%lld%d%d", &n, &p, &q);
    printf("%lld", solve(n));
}