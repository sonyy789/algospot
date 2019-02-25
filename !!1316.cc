#include <cstdio>
using namespace std;
int n, i, ans;
char str[102];
bool alpha[26];
int main(){
    scanf("%d", &n);
    while(n--){
        for(i = 0; i < 26; i++) alpha[i] = false;
        scanf("%s", str+1);
        for(i = 1; str[i] != '\0'; i++){
            if(alpha[str[i]-'a'] && str[i] != str[i-1]) break;
            alpha[str[i]-'a'] = true;
        }
        if(str[i] == '\0') ans++;
    }
    printf("%d", ans);
}