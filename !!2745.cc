#include <cstdio>
char n[21];
int main(){
    int i, a, b, ans = 0;
    scanf("%s%d", n+1, &b);
    for(i = 1; n[i] != '\0'; i++);
    for(--i, a = 1; i > 0; i--, a *= b){
        if(n[i] >= 'A') ans += a*(n[i]-55);
        else ans += a*(n[i]-'0');
    }
    printf("%d", ans);
}