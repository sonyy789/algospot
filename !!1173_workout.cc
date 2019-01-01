#include <cstdio>
int main(){
    int N, m, M, T, R, c, a = 0;
    scanf("%d%d%d%d%d", &N, &m, &M, &T, &R);
    c = m;
    if(m+T > M) {printf("-1"); return 0;}
    while(N){
        if(c+T <= M) c += T, N--;
        else{
            c -= R;
            if(c < m) c = m;
        }
        a++;
    }
    printf("%d", a);
}