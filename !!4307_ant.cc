#include <cstdio>
#include <algorithm>
using namespace std;

int n, i, p, l, t;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &l, &n);
        int min_time = 0, max_time = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &p);
            min_time = max(min_time, min(p, l-p));
            max_time = max(max_time, max(p, l-p));
        }
        printf("%d %d\n", min_time, max_time);
    }
}