#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int i, j, n, val, node_idx, size, cnt;
int tree[262200];

void update(int idx, int diff){
    while(idx > 0){
        tree[idx] += diff;
        idx >>= 1;
    }
}
int find(int a, int b){
    int ret = 0;
    while(a<=b){
        if(a&1) ret += tree[a++];
        if(~b&1) ret += tree[b--];
        a >>= 1, b >>= 1;
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    // indexed tree
    node_idx = 1<<((int)ceil(log2(n)));
    size = (node_idx<<1)+1;
    node_idx--;
    
    // index mapping
    vector<pair<int, int>> I(n+1);
    for(i = 1; i <= n; i++){
        scanf("%d", &val);
        update(node_idx+i, 1);
        I[i] = {val, i};
    }
    sort(&I[1], &I[n+1]);
    
    int s = 1 , e = n;
    for(i = 1; i <= n; i++){
        if(i%2){
            cnt = find(node_idx+1, node_idx+I[s].second-1);
            update(node_idx+I[s++].second, -1);
        }else{;
            cnt = find(node_idx+I[e].second+1, node_idx+n);
            update(node_idx+I[e--].second, -1);
        }
        printf("%d\n", cnt);
    }
}