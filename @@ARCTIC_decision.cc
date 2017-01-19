#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
pair<double, double> arr[101];
double dist[101][101];
double distance(int a, int b)
{
    return sqrt(pow(arr[a].first-arr[b].first,2)+pow(arr[a].second-arr[b].second,2));
}
bool decision(int place, double gap)
{
    queue<int> q;
    q.push(0);
    vector<bool> visited(place, false);
    visited[0] = true;
    int cnt = 1;
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        for(int i = 0; i < place; i++)
            if(!visited[i] && gap >= dist[here][i])
            {
                visited[i] = true;
                cnt++;
                q.push(i);
            }
    }
    return cnt >= place;
}
double opt(int place)
{
    double lo = 0;
    double hi = 1001;
    double mid;
    for(int i = 0; i < 30; i++)
    {
        mid = (lo+hi)/2;
        if(decision(place, mid))
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}
int main()
{
    int t, n;
    double x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(&arr, 0, sizeof(arr));
        memset(&dist, 0, n*n*sizeof(double));
        for(int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &x, &y);
            arr[i].first = x, arr[i].second = y;
        }
        for(int i = 0 ; i < n; i++)
            for(int j = i+1; j < n; j++)
                dist[i][j] = distance(i, j);
        for(int i = 0 ; i < n; i++)
            for(int j = i+1; j < n; j++)
                dist[j][i] = dist[i][j];
        printf("%.2lf\n", opt(n));
    }
}