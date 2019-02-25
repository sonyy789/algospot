#include <cstdio>
int i, j, a, ans;
char str[10];
int main(){
    for(i = 0; i < 8; i++){
        scanf("%s", str);
        for(j = a; j < 8; j +=2) ans += str[j]=='F';
        a = !a;
    }
    printf("%d", ans);
}