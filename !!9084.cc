#include <cstdio>
#define MAX 10001
using namespace std;
int t, n, m, i, j, c;
int dp[MAX];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < MAX; i++) dp[i] = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &c);
            dp[c]++;
            for(j = c+1; j < MAX; j++)
                dp[j] += dp[j-c];
        }
        scanf("%d", &m);
        printf("%d\n", dp[m]);
    }
}