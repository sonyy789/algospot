#include <cstdio>
int main(){
    int n, m, l, a = 0, i = 1, A[1001] = {0, };
    scanf("%d%d%d", &n, &m, &l);
    while(1){
        int f = 0;
        for(i; i <= n; i += l, a++){
            A[i]++;
            if(A[i] == m) {f=1; break;}
        }
        i %= n;
        if(f) break;
    }
    printf("%d", a);
}