#include <cstdio>
int A[3][3][3] = {{1,0,0,1,0,0,1,1,0},{1,0,0,1,1,0,0,1,0},{1,0,0,1,1,0,1,0,0}};
int M[504][504];
int max(int a, int b){return a>b?a:b;}
int main(){
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)  scanf("%d", &M[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            ans = max(ans, M[i][j]+M[i+1][j]+M[i][j+1]+M[i+1][j+1]); // square
            ans = max(ans, M[i][j]+M[i][j+1]+M[i][j+2]+M[i][j+3]); // stick1
            ans = max(ans, M[i][j]+M[i+1][j]+M[i+2][j]+M[i+3][j]); //stick2
            for(int k = 0; k < 3; k++){
                ans = max(ans, M[i][j]*A[k][0][0]+M[i+1][j]*A[k][1][0]+M[i+2][j]*A[k][2][0]+M[i][j+1]*A[k][0][1]+M[i+1][j+1]*A[k][1][1]+M[i+2][j+1]*A[k][2][1]);
                ans = max(ans, M[i][j]*A[k][0][1]+M[i+1][j]*A[k][0][0]+M[i][j+1]*A[k][1][1]+M[i+1][j+1]*A[k][1][0]+M[i][j+2]*A[k][2][1]+M[i+1][j+2]*A[k][2][0]);
                ans = max(ans, M[i][j]*A[k][2][1]+M[i+1][j]*A[k][1][1]+M[i+2][j]*A[k][0][1]+M[i][j+1]*A[k][2][0]+M[i+1][j+1]*A[k][1][0]+M[i+2][j+1]*A[k][0][0]);
                ans = max(ans, M[i][j]*A[k][2][0]+M[i+1][j]*A[k][2][1]+M[i][j+1]*A[k][1][0]+M[i+1][j+1]*A[k][1][1]+M[i][j+2]*A[k][0][0]+M[i+1][j+2]*A[k][0][1]);
                if(k == 3) continue;
                ans = max(ans, M[i][j]*A[k][0][1]+M[i+1][j]*A[k][1][1]+M[i+2][j]*A[k][2][1]+M[i][j+1]*A[k][0][0]+M[i+1][j+1]*A[k][1][0]+M[i+2][j+1]*A[k][2][0]);
                ans = max(ans, M[i][j]*A[k][2][1]+M[i+1][j]*A[k][2][0]+M[i][j+1]*A[k][1][1]+M[i+1][j+1]*A[k][1][0]+M[i][j+2]*A[k][0][1]+M[i+1][j+2]*A[k][0][0]);
                ans = max(ans, M[i][j]*A[k][2][0]+M[i+1][j]*A[k][1][0]+M[i+2][j]*A[k][0][0]+M[i][j+1]*A[k][2][1]+M[i+1][j+1]*A[k][1][1]+M[i+2][j+1]*A[k][0][1]);
                ans = max(ans, M[i][j]*A[k][0][0]+M[i+1][j]*A[k][0][1]+M[i][j+1]*A[k][1][0]+M[i+1][j+1]*A[k][1][1]+M[i][j+2]*A[k][2][0]+M[i+1][j+2]*A[k][2][1]);
            }
        }
    printf("%d\n", ans);
}