#include <cstdio>
int i, ans, s_cnt;
int main(){
    char str[100003];
    scanf("%s", str+1);
    for(i = 1; str[i]!='\0'; i++){
        if(str[i] == '('){
            if(str[i+1] == '(') s_cnt++; 
            else ans += s_cnt, i++;
        }else ans++, s_cnt--;
    }
    printf("%d", ans);
}