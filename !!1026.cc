#include <cstdio>
#include <algorithm>
using namespace std;
int n, i, j, ans;
int A[2][51];
int main(){
    scanf("%d", &n);
    for(i = 0; i < 2; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    sort(A[0], A[0]+n);
    sort(A[1], A[1]+n);
    for(j = 0; j < n; j++)
        ans += A[0][j]*A[1][n-j-1];
    printf("%d", ans);
}