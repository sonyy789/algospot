#include <cstdio>
#include <algorithm>
using namespace std;
int c, n;
pair<int, int> A[10001];
int main(){
    int i, j;
    scanf("%d", &c);
    while(c--){
        scanf("%d", &n);
        for(i = 1; i <= n; i++) scanf("%d", &A[i].second);
        for(i = 1; i <= n; i++) scanf("%d", &A[i].first);
        sort(A+1, A+1+n, greater<pair<int, int>>());
        int ans = 0, sum = 0;
        for(i = 1; i <= n; i++){
            sum += A[i].second;
            ans = max(ans, sum+A[i].first);
        }
        printf("%d\n", ans);
    }
}