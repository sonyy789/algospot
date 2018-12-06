#include <cstdio>
int len, ans, n, m, A[1002][1002];
int main(){
    char in[1001];
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%s", in);
        for(int j = 1; j <= m; j++)
            A[i][j] = (in[j-1]-48) + A[i-1][j]+A[i][j-1]-A[i-1][j-1];
    }
    int comp = 1;
    int y,x;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            while(i+len <= n && j+len <= m && A[i+len][j+len]+A[i-1][j-1]-A[i-1][j+len]-A[i+len][j-1] == comp){
                len++;
                ans = len*len;
                comp = (len+1)*(len+1);
            }
        }
    }
    printf("%d\n", ans);
}    