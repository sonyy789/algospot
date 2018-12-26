#include <cstdio>
int main(){
    int A[151] = {0,}, B[9] = {0,};
    int a, sum = 0;
    for(int i = 1; i <= 8; i++){
        scanf("%d", &a);
        A[a] = i;
    }
    a = 0; 
    for(int i = 150; a < 5; i--)
        if(A[i]) B[A[i]] = 1, sum += i, a++;
    printf("%d\n", sum);
    for(int i = 1; i <= 8; i++)
        if(B[i]) printf("%d ", i); 
}