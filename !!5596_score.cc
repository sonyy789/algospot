#include <cstdio>
int main(){
    int i = 0, A[2][1] = {0,}, c;
    for(i; i <= 8; i++){
        scanf("%d", &c);
        A[i/4][0] += c;
    }
    printf("%d", (A[0][0]>A[1][0]?A[0][0]:A[1][0]));
}