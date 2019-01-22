#include <cstdio>
int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int num = 0, ans = 0;
        while(1){
            num = num*10+1;
            num%=n; ans++;
            if(num == 0) break;
        }
        printf("%d\n", ans);
    }
}