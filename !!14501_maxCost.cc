#include <cstdio>
int P[15];
int main(){
    int i, j, n, t, p, ans = 0;
    scanf("%d", &n);
    for(i =0; i <n; i++){
        scanf("%d %d", &t, &p);
        if(i+t<=n) P[i] += p;
        for(j = t+i; j<n; j++)
            P[j] = P[j]>(P[i])?P[j]:P[i];
    }
    for(i = 0; i < n; i++)
        ans = ans>P[i]?ans:P[i];
    printf("%d\n", ans);
}