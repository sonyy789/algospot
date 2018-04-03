#include <cstdio>
int i, j, n, m, a, b, A[301][301];
int main(){
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++){
            scanf("%d", &a);
            A[i][j] = A[i-1][j]+A[i][j-1]+a-A[i-1][j-1];
        }
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d %d", &a, &b, &i, &j);
        printf("%d\n", A[i][j]-A[a-1][j]-A[i][b-1]+A[a-1][b-1]);
    }
}