#include <cstdio>
#include <algorithm>
using namespace std;
int tree[1<<21], common[1<<21];
int ans, max_val, f_idx, size;
void dfs(int idx, int add_len){
    if(idx >= size) return;
    if(common[idx] > add_len){
        ans += common[idx]-add_len;
        add_len = common[idx];
    }
    dfs((idx<<1),add_len);
    dfs((idx<<1)+1, add_len);
}
int main(){
    int i, j, k;
    scanf("%d",&k);
    size = 1<<(k+1);
    f_idx = size>>1;
    for(i = 2; i < size; i++){
        scanf("%d", &tree[i]);
        ans += tree[i];
        tree[i] += tree[(i>>1)];
    }
    for(i = f_idx; i < size; i++)
        max_val = max(max_val, tree[i]);
        
    for(i = f_idx; i < size; i++)
        common[i] = max_val-tree[i];
    for(i = f_idx-1; i > 1; i--)
        common[i] = min(common[(i<<1)], common[(i<<1)+1]);
    dfs(1, 0);
    printf("%d", ans);
}