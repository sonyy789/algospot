#include <cstdio>
int A[201][3], B[201];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0, k = 1; j < 3; j++, k *= 1000){
            scanf("%d", &A[i][j]);
            B[A[i][j]] += k;
        }
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0, k =1; j < 3; j++, k *= 1000){
            int idx = A[i][j];
            if((B[idx]%(1000*k))/k == 1) sum += idx;
        }
        printf("%d\n", sum);
    }
}