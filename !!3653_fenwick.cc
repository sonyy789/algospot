#include <cstdio>
#define MAX 100001
using namespace std;
int tree[2*MAX], I[MAX];
int t, a, b, n, m, i, j, idx;
int search(int idx){
    int ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
void update(int idx, int diff){
    while(idx <= n+m){
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d",&n, &m);
        for(i = 1; i < 2*MAX; i++) tree[i] = 0;
        for(i = 1; i <= n; i++){
            I[i] = m+i;
            update(I[i],1);
        }
        for(i = m; i > 0; i--){
            scanf("%d", &idx);
            printf("%d ", search(I[idx])-1);
            update(I[idx],-1);
            I[idx] = i;
            update(I[idx], 1);
        }
        printf("\n");
    }
}