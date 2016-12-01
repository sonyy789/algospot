#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <cstring>
#include <unistd.h>
#include <queue>
#define MAXVERTEX 10000
using namespace std;
const int max_value = numeric_limits<double>::max();
vector<vector<pair<int, double>>> adj; // <index, cost>
vector<double> daijkstra(int start, int N)
{
    vector<double> dist(N, max_value);
    priority_queue<pair<double, int>> pq;
    dist[start] = log10(1); 
    pq.push(make_pair(log10(1), start));
    while(!pq.empty())
    {
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first;
            double sum_cost = cost + adj[here][i].second;
            if(dist[there] > sum_cost)
            {
                pq.push(make_pair(-sum_cost, there));
                dist[there] = sum_cost;
            }
        }
    }
    return dist;
}
int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(10);
    int t, n, m, a, b;
    double c;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        adj.clear();
        adj = vector<vector<pair<int, double>>>(n); 
        for(int i = 0; i < m; i++)
        {
            cin>>a>>b>>c;
            adj[a].push_back(make_pair(b, log10(c)));
        }
        vector<double> result = daijkstra(0, n);
        cout<<pow(10, result[n-1])<<"\n";
    }
}