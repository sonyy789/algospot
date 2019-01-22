#include <cstdio>
#include <cstring>
#define MAX 1000001
bool visit[MAX];
int prime[80000], p_idx;
int main(){
    char P[103];
    int k, i, j, len;
    scanf("%s%d", P+1, &k);
    
    // prime num
    prime[++p_idx] = 2;
    for(i = 3; i< k;i+=2){
        if(visit[i]) continue;
        prime[++p_idx] = i;
        int inv = 2*i;
        for(j = i+inv; j < k; j+=inv) visit[j] = true;
    }
    len = strlen(P+1);
    for(i = 1; i <= p_idx; i++){
        int num = 0;
        int prime_num = prime[i];
        for(j = 1; j <= len; j++){
            num = num*10+(P[j]-'0');
            if(num >= prime_num) num %= prime_num;
        }
        if(num == 0){ 
            printf("BAD %d", prime_num);
            return 0;
        }
    }
    printf("GOOD");
}