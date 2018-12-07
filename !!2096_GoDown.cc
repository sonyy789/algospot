#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int main(){
    int n, a, b, c, Mx[3], Mn[3];
    scanf("%d", &n);
    Mx[0] = Mx[1] = Mx[2] = Mn[0] = Mn[1] = Mn[2] = 0;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &a,&b,&c);        
        Mx[0] += a; Mx[1] += b; Mx[2] += c;
        Mx[0] = max(Mx[0], Mx[1]); Mx[2] = max(Mx[1], Mx[2]); Mx[1] = max(Mx[0], Mx[2]);
        Mn[0] += a; Mn[1] += b; Mn[2] += c;
        Mn[0] = min(Mn[0], Mn[1]); Mn[2] = min(Mn[1], Mn[2]); Mn[1] = min(Mn[0], Mn[2]);
    }
    printf("%d %d\n", Mx[1], Mn[1]);
}
