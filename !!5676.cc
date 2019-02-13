#include <cstdio>
using namespace std;
int n, m, i, j, v, nn, val, res, size;
char op;
int tree[262200];
void update(int idx, int val){
    tree[idx] = val;
    while(1){
        idx >>= 1;
        if(idx == 0) return;
        tree[idx] = tree[idx<<1]*tree[(idx<<1)+1];
    }
}
int search(int a, int b){
    int ans = 1;
    while(a <= b){
        if(a & 1) ans *= tree[a++];
        if(~b & 1) ans *= tree[b--];
        a >>= 1, b >>= 1;
    }
    return ans>0?'+':(ans<0?'-':'0');
}
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        for(nn = 1; nn < n; nn <<= 1);
        size = nn<<1;
        nn--;
        for(i = 1; i < size; i++) tree[i] = 1;
        for(i = 1; i <= n; i++){
            scanf("%d", &val);
            update(nn+i, val>0?1:(val<0?-1:0));
        }
        while(m--){
            scanf(" %c %d %d", &op, &i, &v);
            if(op == 'C') update(nn+i, v>0?1:(v<0?-1:0));
            else printf("%c", search(nn+i, nn+v));
        }
        printf("\n");
    }
}