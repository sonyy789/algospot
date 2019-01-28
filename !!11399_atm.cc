#include <cstdio>
#include <algorithm>

using namespace std;

int n, i, tot;
int P[1001];
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &P[i]);
    sort(&P[1], &P[n+1]);
    for(i = 1; i <= n; i++){
        P[i] += P[i-1];
        tot += P[i];
    }
    printf("%d", tot);
}
