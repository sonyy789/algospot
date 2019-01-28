#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a, b, c, d, cost;
int main(){
    scanf("%d%d", &n, &m);
    c = d = 1e9;
    while(m--){
        scanf("%d%d", &a,&b);
        c = min(a, c);
        d = min(b, d);
    }
    cost = (n/6)*c;
    if(n%6) cost += min(c, (n%6)*d);
    cost = min(cost, n*d);
    printf("%d", cost);
}