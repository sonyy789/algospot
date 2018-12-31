#include <cstdio>
#include <cstring>
int n, A, ans, S[50];
void comb(int idx, int k, int r){
    if(k == 0){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if((A&S[i])!=S[i]) continue;
            cnt++;
        }
        ans = ans > cnt?ans:cnt;
        return;
    }
    int a = 1<<idx;
    for(int i = idx; i < 26 && r >= k; i++, a<<=1){
        if(A&a) continue;
        A += a;
        comb(i+1, k-1, r-1);
        A -= a;
    }
}
int main(){
    int k;
    char s[17];
    scanf("%d%d", &n, &k);
    A |= ((1<<0)+(1<<2)+(1<<8)+(1<<13)+(1<<19));
    k -= 5;
    if(k < 0) {printf("0"); return 0;}
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        for(int j = 0; j < strlen(s); j++)
            S[i] |= (1<<(s[j]-'a'));
    }
    comb(1, k, 21);
    printf("%d", ans);
}