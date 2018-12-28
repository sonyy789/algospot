#include <cstdio>
#include <cmath>
int main(){
    int i, n, w, h;
    scanf("%d%d%d", &n,&w,&h);
    w = sqrt(w*w+h*h);
    for(i = 0; i < n; i++){
        scanf("%d", &h);
        if(h > w) printf("NE\n");
        else printf("DA\n");
    }
}