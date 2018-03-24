#include <cstdio>
int main(){
    int n, m, lm, ans = 1, A[51][51];
    char s[51];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        for(int j = 0; j < m; j++)
            A[i][j] = s[j]-'0';
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp = 1; int c = A[i][j];
            for(int k = 1; k+i < n && k+j < m; k++)
                if(c==A[i+k][j] && c==A[i][j+k] && c==A[i+k][j+k]) temp = k+1;
            ans = ans > temp? ans:temp;
        }
    }
    printf("%d\n", ans*ans);
}