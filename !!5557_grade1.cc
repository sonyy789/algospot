#include <cstdio>
int main(){
    int n, A[101];
    long long B[101][21] = {0,};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    B[0][A[0]] = 1;
    for(int i = 1; i < n-1; i++){
        int val = A[i];
        for(int j = 0; j < 21; j++){
            if(j-val >= 0) B[i][j-val] += B[i-1][j];
            if(j+val <= 20) B[i][j+val] += B[i-1][j];
        }
    }
    printf("%lld",B[n-2][A[n-1]]);
}