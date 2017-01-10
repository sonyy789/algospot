#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<double>> adj;
const double inf = 1415*21;
int t,n;
map<pair<int,int>, double> cache;
double best;
double prim(int here, int visit)
{
    double &ret = cache[make_pair(here, visit)];
    int stat = visit;
    if(ret) return ret;
    vector<double> mincost(n, inf);
    ret = mincost[here] = 0;
    stat -= (1<<here);
    int N = n - __builtin_popcount(stat);
    for(int i = 0; i < N; i++)
    {
        int u = -1;
        for(int k = 0; k < n; k++)
        {
            if(stat & (1<<k)) continue;
            if(( u == -1 || (mincost[u] > mincost[k]) ))
                u = k;
        }
        stat += (1<<u);
        ret += mincost[u];
        for(int j = 0; j < n; j++)
        {
            int cost = adj[u][j];
            if(stat & (1<<j)) continue;
            if(cost < mincost[j])
                mincost[j] = cost;
        }
    }
    return ret;
}
void tsp3(int here, double sum, int depth, int visit)
{
    if(depth == n) {best = min(best, sum); return;}
    if(depth > 0)
        if(best <= sum + prim(here,visit)) return;
    for(int i = 0; i < n; i++)
    {
        int temp = (1<<i);
        if(visit & temp) continue;
        tsp3(i, sum+adj[here][i], depth+1, visit + temp);
    }
}
int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(10);
    cin>>t;
    while(t--)
    {
        cache.clear();
        best = inf;
        cin>>n;
        adj = vector<vector<double>>(n+1, vector<double>(n, 0));
        for(int i = 0; i < n; i++) adj[n][i] = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) cin>>adj[i][j];
        tsp3(n, 0, 0, 0);
        cout<<best<<"\n";
    }
}