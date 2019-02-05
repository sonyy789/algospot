#include <cstdio>
int t, n, i, j, p_idx;
bool check[100000];
int prime[10000];
int main(){
    prime[++p_idx] = 2;
    for(i = 3; i <= 100000; i+=2){
        int k = i<<1;
        if(check[i]) continue;
        else prime[++p_idx] = i;
        for(j = i+k; j <= 100000; j += k) check[j] = true;
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        for(i = 1; i <= p_idx && n; i++){
            if(n%prime[i] == 0){ 
                int cnt = 0;
                while(n%prime[i] == 0){
                    n /= prime[i];
                    cnt++;
                }
                printf("%d %d\n", prime[i], cnt);
            }
        }
    }
}