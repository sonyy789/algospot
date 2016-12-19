#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_V 501
using namespace std;
const int inf = 50001;
int adj[MAX_V][MAX_V];
int worst[MAX_V][MAX_V];
vector<pair<int,int>> insp;
int floyd(int s)
{   
    for(int i = 0; i < s; i++)  worst[i][i] = adj[i][i] = 0;
    sort(insp.begin(), insp.end());
    for(int k = 0; k < s; k++)
    {
        int value = insp[k].first;
        int node = insp[k].second;
        for(int a = 0; a < s; a++)
            for(int b = 0; b < s; b++)
            {
                adj[a][b] = min(adj[a][b], adj[a][node] + adj[node][b]);
                worst[a][b] = min(adj[a][node] + value + adj[node][b], worst[a][b]);
            }
    }
}
int main()
{
    int v, e, input, a, b, d, c, start, end;
    scanf("%d%d", &v, &e);
    insp = vector<pair<int, int>>(v);
    for(int i = 0; i < v; i++)
        scanf("%d", &input), insp[i] = make_pair(input, i);
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            worst[i][j] = adj[i][j] = inf;
    for(int i = 0; i < e; i++)
    {
        scanf("%d%d%d", &a, &b, &d);
        a--, b--;
        adj[a][b] = adj[b][a] = d;
        worst[a][b] = worst[b][a] = d;
    }
    floyd(v);
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d%d", &start, &end);
        printf("%d\n", worst[--start][--end]);
    }
}
