#include <cstdio>
int main(){
    int i, a, A[31] = {0,};
    for(i = 0; i < 28; i++){
        scanf("%d", &a);
        A[a] = 1;
    }
    for(i = 1; i <= 30; i++){
        if(A[i] == 0) printf("%d\n", i);
    }
}