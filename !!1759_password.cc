#include <cstdio>
#include <algorithm>
using namespace std;
char s[16], ans[16];
bool chk[16];
int l, c;
void solve(int idx, int cnt, int a, int b){
    if(cnt == l){
        if(a >= 1 && b >= 2)
            printf("%s\n", ans);
        return;
    }
    for(int i = idx; i < c; i++){
        ans[cnt] = s[i];
        if(chk[i]) solve(i+1, cnt+1, a+1, b);
        else solve(i+1, cnt+1, a, b+1);
    }
}
int main(){
    scanf("%d%d",&l,&c);
    for(int i = 0; i < c; i++) scanf(" %c", &s[i]);
    sort(&s[0], &s[c]);
    for(int i = 0; i < c; i++) 
        if(s[i] == 'a' || s[i] =='e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') chk[i] = true;
    solve(0, 0, 0, 0);
}