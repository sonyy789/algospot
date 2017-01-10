#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<double>> adj;
vector<int> visited;
const double inf = 1415*21;
int t,n;
map<pair<int,int>, double> cache;
double best;
int prim(int here, int visit)
{
    double &ret = cache[make_pair(here, visit)];
    if(ret) return ret;
    vector<int> stat = visited;
    vector<double> mincost(n, inf);
    ret = mincost[here] = 0;
    int N = stat[here] = 0;
    for(int data : stat) if(!data) N++;
    for(int i = 0; i < N; i++)
    {
        int u = -1;
        for(int k = 0; k < n; k++)
            if(!stat[k] &&  ( u == -1 || (mincost[u] > mincost[k]) ))
                u = k;
        stat[u] = 1;
        ret += mincost[u];
        for(int j = 0; j < n; j++)
        {
            int cost = adj[u][j];
            if(!stat[j] && cost < mincost[j])
                mincost[j] = cost;
        }
    }
    return ret;
}
void tsp3(int here, double sum, int depth, int visit)
{
    if(depth == 1) sum = 0;
    if(depth == n) {best = min(best, sum); return;}
    if(best <= sum + prim(here,visit)) return;
    for(int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        visited[i] = 1;
        tsp3(i, sum+adj[here][i], depth+1, visit + (1<<i));
        visited[i] = 0;
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
        visited = vector<int>(n, 0);
        adj = vector<vector<double>>(n, vector<double>(n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) cin>>adj[i][j];
        tsp3(0, 0, 0, 0);
        cout<<best<<"\n";
    }
}