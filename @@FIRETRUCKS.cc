#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <cstring>
#define MAX_VERTEX 1001
using namespace std;
const int inf = numeric_limits<int>::max();
vector<vector<pair<int, int>>> adj;
vector<int> daijkstra(int start, int size)
{
    vector<int> dist(size+1, inf);
    priority_queue<pair<int, int>> pq; // <cost, index>
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(cost > dist[here]) continue;
        for(int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first;
            int temp_cost = adj[here][i].second + cost;
            if(temp_cost <  dist[there])
            {
                dist[there] = temp_cost;
                pq.push(make_pair(-temp_cost, there));
            }
        }
    }
    return dist;
}
int main()
{
    int t, v, e, n, m, a, b, c, input;
    scanf("%d", &t);
    while(t--)
    {
        adj.clear();
        scanf("%d%d%d%d", &v, &e, &n, &m);
        adj = vector<vector<pair<int, int>>>(v+1);
        vector<int> fighting;
        vector<int> fire;
        for(int i = 0; i < e; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }
        for(int i = 0; i < n; i++)
            scanf("%d", &input), fire.push_back(input);
        for(int i = 0; i < m; i++)
            scanf("%d", &input), fighting.push_back(input);
        for(int i = 1; i < fighting.size(); i++)
                adj[fighting[0]].push_back(make_pair(fighting[i], 0));
        vector<int> result = daijkstra(fighting[0], v);
        int ans = 0;
        for(int data : fire)
            ans += result[data];
        printf("%d\n", ans);
    }
}