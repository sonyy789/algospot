#include <cstdio>
#include <vector>
#define MAX_V 200
using namespace std;
const int inf = 200000; // multiply MAX COST by 2
int adj[MAX_V][MAX_V];
void floyd(vector<int> &set, int s)
{
    for(int p : set)
        for(int i = 0; i < s; i++)
            for(int j = 0; j < s; j++)
                if(adj[i][j] > adj[i][p] + adj[p][j])
                    adj[i][j] = adj[i][p] + adj[p][j];
}
int main()
{
    int t, a, b, c, n, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &x, &y);
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = inf;
        for(int i = 0; i < x; i++)
            scanf("%d%d%d", &a, &b, &c), adj[a][b] = adj[b][a] = c;
        vector<int> stop(n);
        for(int i = 0; i < n; i++) stop[i] = i, adj[i][i] = 0;
        floyd(stop, n);
        while(y--)
        {
            scanf("%d%d%d", &a, &b, &c);
            vector<int> node;
            node.push_back(a), node.push_back(b);
            if(adj[a][b] <= c) ans++;
            else
            {
                adj[a][b] = adj[b][a] = c;
                floyd(node, n);
            }
        }
        printf("%d\n", ans); 
    }
}
