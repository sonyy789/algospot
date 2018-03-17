#include <cstdio>
bool arr[101][101];
int main(){
    int n, m, i, j, k;
    scanf("%d %d",&n, &m);
    for(i = 0; i < n; i++)
        arr[i][i] = true;
    while(m--){
        scanf("%d %d", &i, &j);
        i--; j--;
        arr[i][j] = true;
    }
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++){
                arr[i][j] |= arr[i][k]&arr[k][j];
    }        
    for(i = 0; i < n; i++){
        int sum = 0;
        for(j = 0; j < n; j++)
            sum += (arr[i][j]||arr[j][i])?0:1;
        printf("%d\n", sum);
    }
}