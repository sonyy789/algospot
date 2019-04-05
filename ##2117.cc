#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int tc, z, n, m, data;
int C[41], K[41];
pair<int, int> home[401];
int main(){
    int i, j, k;
    for(k = 1; k <= 40; k++)
        K[k] = (k*k)+((k-1)*(k-1));
    scanf("%d", &tc);
    for(z=1;z<=tc;z++){
        int ans = 0, home_idx = 0;
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++){
                scanf("%d", &data);
                if(data) home[++home_idx] = {i,j};
            }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                for(k = 1; k <= home_idx; k++)
                    C[abs(i-home[k].first)+abs(j-home[k].second)]++;
                int home_cnt = 0;
                for(k = 1; k <= 40; k++){
                    home_cnt += C[k-1];
                    if(K[k] <= home_cnt*m) ans = max(ans, home_cnt);
                    C[k-1] = 0;
                }
            }
        }
        printf("#%d %d\n", z, ans);
    }    
}