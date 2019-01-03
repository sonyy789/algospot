#include <cstdio>
long long S[21];
int A[21];
int main(){
    int n, m;
    long long k, a =1;
    scanf("%d%d", &n, &m);
    S[n] = 1;
    for(int i = 1; i <= n; i++){
        a *= i;
        S[n-i] = a; 
    }
    if(m == 1){
        scanf("%lld", &k);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(A[j]) continue;
                if(S[i]>=k){
                    A[j] = 1;
                    printf("%d ", j);
                    j +=n;
                    continue;
                }
                k -= S[i];
            }
        }
    }else{
        k = 1;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a);
            for(int j = 1; j < a; j++){
                if(A[j]) continue;
                k += S[i];
            }
            A[a] = 1;
        }
        printf("%lld", k);
    }
}