#include <cstdio>
int main(){
    int i, j, k, n, m, A[101], sum = -1;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    for(i = 0; i < n-2; i++)
        for(j = i+1; j < n-1; j++)
            for(k = j+1; k < n; k++){
                int tmp = (A[i]+A[j]+A[k]);
                if(tmp <= m && (m-tmp) < (m-sum)) sum = tmp;
                if(sum == m) i +=n, j += n, k += n;
            }
    printf("%d", sum);
}