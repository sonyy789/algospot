#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;
int A[500001];
long long I[1048600];
void update(int idx){
    I[idx] = 1;
    while(1){
        idx/=2;
        if(idx == 0) break;
        I[idx] = I[idx*2]+I[idx*2+1];
    }
}
long long search(int a, int b){
    if(a>b) return 0;
    long long ret = 0;
    while(a<=b){
        if(a&1) ret += I[a++];
        if(~b&1) ret += I[b--];
        a >>= 1; b >>= 1;
    }
    return ret;
}
int main(){
    int n, val;
    scanf("%d",&n);
    int idx = 1<<((int)ceil(log2(n)));
    int size = (idx<<1)+1;
    unordered_map<int, int> um;
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for(int i = 1; i <= n; i++){
        scanf("%d", &val);
        um[val] = i;
    }
    long long ans = 0;
    for(int i = n; i >= 1; i--){
        int uIdx = um[A[i]];
        int curr = idx+uIdx-1;
        long long cross = search(idx, curr-1);
        ans += cross;
        update(curr);
    }
    printf("%lld", ans);
}