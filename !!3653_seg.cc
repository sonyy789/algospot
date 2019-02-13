#include <cstdio>
#define MAX 524300
using namespace std;
int t, a, b, n, m, res, num, node_idx;
int tree[MAX], I[100001];
void update(int idx, int diff){
    while(idx>0){
        tree[idx] += diff;
        idx >>= 1;
    }
}
int main(){
    int i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(i = 0; i < MAX; i++) tree[i] = 0;
        for(node_idx=1; node_idx < n+m; node_idx<<=1);
        node_idx--;
        for(i = 1; i <= n; i++){
            I[i] = n-i+1;    
            update(node_idx+i, 1);
        }
        for(i = 0; i < m; i++){
            scanf("%d", &num);
            res = 0;
            a = node_idx+I[num]+1;
            b = node_idx+n+i;
            while(a <= b){
                if(a & 1) res += tree[a++];
                if(~b & 1) res += tree[b--];
                a >>= 1, b >>= 1;
            }
            printf("%d ", res);
            update(node_idx+I[num],-1);
            I[num] = n+i+1;
            update(node_idx+I[num], 1);
        }
        printf("\n");
    }
}
