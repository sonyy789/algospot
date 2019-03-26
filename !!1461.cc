#include <cstdio>
int n, m, p_idx, n_idx, ans, tmp1, tmp2, first;
int A[10001], P[10001], N[10001];
int main(){
    int i, j, pos;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", &pos);
        if(pos > 0) P[pos]++;
        else N[-pos]++;
    }
    for(i = 10000; i > 0; i--){
        if(first == 0 && (P[i]||N[i])) first = i;
        if(P[i]){
            if(P[i] <= tmp1) tmp1 -= P[i], P[i] = 0;
            else{
                P[i] -= tmp1;
                tmp1 = (m-(P[i]%m))%m;
                if(P[i]) ans += ((((P[i]-1)/m)+1)*i)<<1;
            }
        }
        if(N[i]){
            if(N[i] <= tmp2) tmp2 -= N[i], N[i] = 0;
            else{
                N[i] -= tmp2;
                tmp2 = (m-(N[i]%m))%m;
                if(N[i]) ans += ((((N[i]-1)/m)+1)*i)<<1;
            }
        }
    }
    printf("%d", ans-first);
}