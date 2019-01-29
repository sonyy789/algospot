#include <cstdio>
#include <algorithm>
using namespace std;
struct Point{
    int x, y;
    bool operator <(const Point &P) const{
        return x==P.x?y<P.y:x<P.x;
    }
}P[100001];
int n, i;
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d %d", &P[i].x,&P[i].y);
    sort(&P[1], &P[n+1]);
    for(i = 1; i <= n; i++)
        printf("%d %d\n", P[i].x, P[i].y);
}