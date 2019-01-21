#include <cstdio>
int B[1001];
int main(){
    int n, m, p = 1, i, c, cnt;
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++)
        scanf("%d", &B[i]);
    for(cnt = 1; ; cnt++){
        scanf("%d", &c);
        p += c;
        if(p >= n) break;
        p += B[p];
        if(p >= n) break;
    }
    printf("%d", cnt);
}