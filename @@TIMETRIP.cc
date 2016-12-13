#include <cstdio>
#include <vector>
#include <cstring>
#include <limits>
using namespace std;
const int inf = numeric_limits<int>::max();
vector<vector<pair<int, int>>> adj;
int cycle_chk(vector<int> &set)
{
    if(set[0] != -1) return 1;
    int count = 1;
    int limit = set.size();
    int here = 1;
    while(1)
    {
        if(set[here] == here) return 1;
        here = set[here];
        if(here == 0) return 0;
        count++;
        if(count > limit) return 1;
    }
}
int bellanford(int start, int flags)
{
    int size = adj.size();
    bool updated;
    vector<int> upper(size, inf);
    vector<int> path(size, -1);
    upper[start] = 0;
    for(int cnt = 0; cnt < size-1; cnt++)
    {
        updated = false;
        for(int here = 0; here < size; here++)
        {
            if(upper[here] == inf) continue;
            for(int i = 0; i < adj[here].size(); i++)
            {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                int temp = upper[here] + cost; 
                if(upper[there] > temp )
                {
                    updated = true;
                    upper[there] = temp;
                    path[there] = here;
                }
            }
        }
        if(!updated) break;
    }
    if(upper[1] == inf)
    {
        printf("UNREACHABLE");
        return 1;
    }
    if(updated)
    {
        if(cycle_chk(path))
        {
            printf("INFINITY ");
            return 0;
        }
    }
    if(flags) upper[1] = -upper[1];
    printf("%d ", upper[1]);
    return 0;
}

int main()
{
    int c, v, w, a, b, d;
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d%d", &v, &w);
        adj.clear();
        adj = vector<vector<pair<int, int>>>(v);
        for(int i = 0; i < w; i++)
        {
            scanf("%d%d%d", &a, &b, &d);
            adj[a].push_back(make_pair(b,d));
        }
        for(int i = 0; i < 2; i++)
        {
            if(bellanford(0, i)) break;
            for(int here = 0; here < v; here++)
                for(int k = 0; k < adj[here].size(); k++)
                    adj[here][k].second= -adj[here][k].second;
        }
        printf("\n");
    }
}