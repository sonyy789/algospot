#include <cstdio>
#define MAX 101
int inf = 1e9;
int arr[101][101];
int min(int a, int b) {return a<b?a:b;}
int main(){
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            arr[i][j] = inf;
        arr[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        arr[a-1][b-1] = min(arr[a-1][b-1], c);
    }
    //floyd;
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", arr[i][j]!=inf?arr[i][j]:0);
        printf("\n");
    }
}