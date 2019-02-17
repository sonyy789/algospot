#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int n, m, i, j;
int A[1001][1001], up[1001], lr[2][1001];
int main(){
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            scanf("%d", &A[i][j]);
    lr[0][0] = lr[1][0] = lr[0][m+1] = lr[1][m+1] = -2e9;
    for(j = 1; j <= m; j++)
        up[j] = up[j-1]+A[1][j];
    for(i = 2; i <= n; i++){
        for(j = 1; j <= m; j++)
            lr[0][j] = max(up[j], lr[0][j-1])+A[i][j];
        for(j = m; j >= 1; j--){
            lr[1][j] = max(up[j], lr[1][j+1])+A[i][j];
            up[j] = max(lr[0][j], lr[1][j]);
        }
    }
    printf("%d", up[m]);
}