#include <cstdio>
int V[501][501], I[501];
int main(){
    int n, m, a, b, ans = 0;
    scanf("%d%d",&n, &m);
    while(m--){
        scanf("%d%d", &a, &b);
        V[a][b] = V[b][a] = 1;
    }
    I[1] = 1;
    for(int i = 2; i <= n; i++)
        if(V[1][i]){
            if(I[i] == 0) I[i] = 1, ans++;
            for(int j = 1; j <= n; j++)
                if(V[i][j] && I[j] == 0) I[j] = 1, ans++;
        }
    printf("%d", ans);
}