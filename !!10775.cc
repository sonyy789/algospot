#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int g, p, g_num, node_idx, size, ans;
int tree[262200];
void update(int idx, int val){
    tree[idx] = val;
    do{
        idx>>=1;
        tree[idx] = max(tree[idx<<1], tree[(idx<<1)|1]);
    }while(idx > 0);
}
int find(int a, int b){
    int ret = 0;
    while(a <= b){
        if(a&1) ret = max(ret, tree[a++]);
        if(~b&1) ret = max(ret, tree[b--]);
        a >>= 1, b >>= 1;
    }
    return ret;
}
int main(){
    int i;
    scanf("%d%d",&g,&p);
    node_idx = 1<<((int)ceil(log2(g)));
    size = node_idx<<1;
    node_idx--;
    for(i = 1; i <= g; i++) update(node_idx+i, i);
    while(p--){
        scanf("%d", &g_num);
        int left = find(node_idx+1, node_idx+g_num);
        if(left){
            ans++;
            update(node_idx+left, 0);
        }else break;
    }
    printf("%d", ans);
}