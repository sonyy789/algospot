#include <cstdio>
int main(){
    int n, num, ans = -1;
    scanf("%d", &n);
    for(int i = n/5; i >= 0; i--){
        num = n;
        num -= i*5;
        if(num%3 == 0){
            ans = i+num/3;
            break;
        }
    }
    printf("%d\n", ans);
}
