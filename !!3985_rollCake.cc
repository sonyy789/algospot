#include <cstdio>

bool L[1001];
int a, b, c, d, s, e, n, i, j, l;

int main(){
    scanf("%d%d", &l, &n);
    for(i = 1; i <= n; i++){
        scanf("%d%d",&s,&e);
        if(e-s> a) a = e-s, b = i;
        int cnt = 0;
        for(j = s; j <= e; j++){
            if(L[j]) continue;
            L[j] = true; cnt++;
        }
        if(cnt > c) c = cnt, d = i;
    }
    printf("%d\n%d", b, d);
}