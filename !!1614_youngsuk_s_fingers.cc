#include <cstdio>
typedef long long int lld;
int a,b;
lld ans;
int main(){
    scanf("%d%d",&a,&b);
    if(a == 1){
        ans = (lld)8*b;
    }else if(a==5){
        ans = (lld)8*b+4;
    }else{ 
        ans = (lld)8*(b/2);
        if(b%2) ans += 9-a;
        else ans += a-1; 
    }
    printf("%lld", ans);
}