#include <cstdio>
using namespace std;
int n, k, i, j, nn, m;
int tree[262200];
void update(int idx, int diff){
    while(idx > 0){
        tree[idx] += diff;
        idx >>= 1;
    }
}
int search(int cnt){
    int idx = 1;
    while(idx <= nn){
        idx <<= 1;
        if(cnt > tree[idx]) cnt -= tree[idx], idx++;
    }
    return idx-nn;
}
int main(){
    scanf("%d%d", &n, &k);
    for(nn = 1; nn < n; nn <<= 1);
    nn--;
    for(i = 1; i <= n; i++) update(nn+i, 1);
    m = k;
    printf("<");
    for(i = n; i > 1; i--){
        m = (m%i)?(m%i):i;
        int res = search(m);
        printf("%d, ", res);
        update(nn+res, -1);
        m += (k-1);
    }
    printf("%d>",search(1));
}