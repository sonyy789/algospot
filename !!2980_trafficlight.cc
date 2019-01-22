#include <cstdio>
int main(){
    int n,l,d,r,g,t=0,dist=0;
    scanf("%d%d", &n,&l);
    while(n--){
        scanf("%d%d%d",&d,&r,&g);
        t += d-dist; dist = d;
        int a = t%(r+g);
        if(a < r) t += r-a;
    }
    printf("%d",t+l-dist);
}