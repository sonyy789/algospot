#include <cstdio>
int main(){
    int n, m, s, t = 0, f= 1;
    char c;
    scanf("%d%d", &m, &n);
    while(n--){
        scanf("%d %c", &s, &c);
        t += s;
        if(t >= 210) f = 0;
        if(c == 'T' && f) m = (m%8)+1;    
    }
    printf("%d", m);
}