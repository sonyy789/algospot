#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int c, n, t, d, p, pos;
double P[51], dp[101][51];
vector<int> adj[51];
int main(){
    int i, j, k;
    scanf("%d", &c);
    while(c--){
        scanf("%d%d%d", &n, &d, &p);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &pos);
                if(pos) adj[i].push_back(j);
            }
            if(adj[i].size()) P[i] = (double)1/adj[i].size();
        }
        dp[0][p] = 1;
        for(i = 0; i < d; i++)
            for(j = 0; j < n; j++)
                for(int next:adj[j])
                    dp[i+1][next] += dp[i][j]*P[j];
        scanf("%d", &t);
        while(t--){
            scanf("%d", &p);
            printf("%.8lf ", dp[d][p]);
        }printf("\n");
        
        //init
        for(i = 0; i < n; i++) adj[i].clear();
        memset(&dp, 0, sizeof(dp));
        memset(&P, 0, sizeof(P));
    }
}
