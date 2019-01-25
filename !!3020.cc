#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int i, j, n, h, node_idx, size, len1, len2;
int tree[1048600];
void update(int a, int b, int fa, int fb, int idx){
    if(b < fa || fb < a) return;
    if(fa <= a && b <= fb){
        tree[idx]++;
        return;
    }
    int mid = (a+b)/2;
    update(a, mid, fa, fb, idx*2);
    update(mid+1, b, fa, fb, idx*2+1);
}
int find(int idx){
    int ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx >>= 1;
    }
    return ret;
}
int main(){
    scanf("%d%d",&n, &h);
    node_idx = 1<<((int)ceil(log2(h)));
    size = (node_idx<<1);
    node_idx--;
    for(i = 1; i <= n/2; i++){
        scanf("%d%d", &len1, &len2);
        update(node_idx+1, size-1, node_idx+1, node_idx+len1, 1);
        update(node_idx+1, size-1, node_idx+h-len2+1, node_idx+h, 1);
    }
    int ans = 2e9, ans_cnt = 0;
    for(i = 1; i <= h; i++){
        int wall_cnt = find(node_idx+i);
        if(wall_cnt < ans){
            ans = wall_cnt;
            ans_cnt =  1;
        }else if(wall_cnt == ans){
            ans_cnt++;
        }
    }
    printf("%d %d", ans, ans_cnt);
}