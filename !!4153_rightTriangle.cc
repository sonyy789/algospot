#include <cstdio>
int main(){
    int a, b, c;
    while(1){
        scanf("%d%d%d", &a, &b, &c);
        if(a==0) break;
        a*=a; b*=b; c*= c;
        (a == b+c || b ==a+c || c ==a+b)?printf("right\n"):printf("wrong\n");
    }
}