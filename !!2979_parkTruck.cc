#include <cstdio>
int main(){
    int a, b, F[4], A[101] = {0,};
    scanf("%d%d%d", &F[1], &F[2], &F[3]);
    F[0] = 0; F[2] *= 2; F[3] *= 3;
    for(int i = 0; i < 3; i++){
        scanf("%d%d", &a, &b);
        for(int j =a; j < b; j++) A[j]++;
    }
    int fee = 0;
    for(int i = 1; i <= 100; i++)
        fee += F[A[i]];
    printf("%d", fee);
