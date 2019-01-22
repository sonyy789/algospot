#include <cstdio>
bool V[2000001];
int main(){
    int i, j, n, c, val, ans = 0;
    scanf("%d%d", &n, &c);
    for(i = 1; i <= n; i++){
        scanf("%d",&val);
        if(V[val]) continue;
        for(j = val; j <= c; j+= val)
            if(V[j] == 0) V[j] = true, ans++;
    }
    printf("%d", ans);
}