#include <cstdio>
int len, i, j, a, l, r;
char str[1002];
int main(){
    scanf("%s", str+1);
    for(;str[++i] != '\0';);
    len = i-1; a = len-1;
    for(i = 1; i < len; i++){
        l = i, r = len;
        while(l <= r && str[l]==str[r]){l++, r--;}
        if(l > r) {a = i-1; break;}
    }
    printf("%d", len+a);
}