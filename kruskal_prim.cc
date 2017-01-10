#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
const int inf = 10000000;
using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int> root, ran;
int find(int k)
{
    if(k == root[k]) return k;
    return root[k] = find(root[k]);
}
int merge(int a, int b)
{
    a = find(a), b = find(b);
    if(ran[a] < ran[b]) swap(a, b);
    if(ran[a] == ran[b]) ran[a]++;
    root[b] = a;
    return a;
}
int kruskal(int n)
{
    int ret = 0;
    root = vector<int>(n);
    for(int i = 0; i < n; i++) root[i] = i;
    ran = vector<int>(n, 0);
    vector<pair<int, int>> selected;
    vector<pair<int, pair<int, int>>> mincost;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j].first, cost = adj[i][j].second;
            mincost.push_back(make_pair(cost, make_pair(i,v)));
        }
    sort(mincost.begin(), mincost.end());
    for(int i = 0; i < mincost.size(); i++)
    {
        int cost = mincost[i].first;
        int u = mincost[i].second.first, v = mincost[i].second.second;
        if(find(u) == find(v)) continue;
        merge(u, v);
        selected.push_back(make_pair(u,v));
        ret += cost;
    }
    return ret;
}
int prim(int V)
{
    vector<pair<int, int>> selected;
    vector<bool> stat(V, false);
    vector<int> mincost(V, inf), parent(V, -1);
    int ret = 0;
    mincost[0] = parent[0] = 0;
    for(int i = 0; i < V; i++)
    {
        int u = -1;
        for(int v = 0; v < V; v++)
            if(!stat[v] &&  ( u == -1 || (mincost[u] > mincost[v]) ))
                u = v;
        cout<<u<<endl;
        if(parent[u] != u)
            selected.push_back(make_pair(parent[u], u));
        stat[u] = true;
        ret += mincost[u];
        for(int i = 0; i < adj[u].size(); i++)
        {
            int cost = adj[u][i].second;
            int v = adj[u][i].first;
            if(!stat[v] && cost < mincost[v])
            {
                mincost[v] = cost;
                parent[v] = u;
            }
        }
    }
    return ret;
}
int main()
{
    int v, e, a, b, c;
    cin>>v>>e;
    adj = vector<vector<pair<int, int>>>(v);
    for(int i = 0; i < e; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    //kruskal(v);
    //prim(v);
}