#include <cstdio>
#include <cstring>
int main(){
    int i, j , k, r, n, t, cnt = 1, p[168], dp[1000] = {0};
    p[0] = 2;
    for(i = 3; i <= 999; i+=2){
        if(!dp[i]) p[cnt++] = i;
        else continue;
        //if(i > 32) continue; >> eratosthenes's prime number >> if condition make v decrease
        for(j = i; j <= 999; j+=i)
            dp[j] = 1;
    }
    memset(&dp, 0, sizeof(dp));
    for(i = 0; i < cnt; i++)
        for(j = i; j < cnt; j++){
            if(p[i]+p[j] > 999) break;
            for(k = j; k < cnt; k++){
                int idx = p[i]+p[j]+p[k];
                if(idx > 999) break;
                dp[idx]++;
            }
        }
    scanf("%d", &t);
    for(r = 1; r <= t; r++){
        scanf("%d", &n);
        printf("#%d %d\n", r, dp[n]);
    }
}