#include <cstdio>
#define MIN(a,b) a<b?a:b
int inf = 1e9;
int arr[101][101];
int main(){
    int n, m, i, j, k, ans, sum, val = inf;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) arr[i][j] = inf;
        arr[i][i] = 0;
    }
    while(m--){
        scanf("%d %d", &i, &j);
        i--; j--;
        arr[i][j] = arr[j][i] = 1;
    }
    //floyd
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                arr[i][j] = MIN(arr[i][j], arr[i][k]+arr[k][j]);
    for(i = 0; i < n; i++){
        sum = 0;
        for(j = 0; j < n; j++)
            sum += arr[i][j];
        if(val >sum){
            val = sum; ans = i+1;
        }
    }
    printf("%d\n", ans);
}