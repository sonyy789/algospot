#include <cstdio>
#include <vector>
using namespace std;
vector<int> L, M, G;
bool decision(int cnt, int place, int N)
{
    int ret = 0;
    for(int i = 0; i < N; i++)
    {
        if(place > L[i])
        {
            ret += ((M[i]/G[i])+1);
            continue;
        }
        int temp = place-(L[i]-M[i]);
        if(temp < 0) continue;
        ret += ((temp/G[i])+1);
    }
    return ret >= cnt;
}
int opt(int city, int place)
{
    int lo = 0;
    int hi = 8030001;
    int mid;
    for(int i = 0; i < 100; i++)
    {
        mid = (lo+hi)/2;
        if(decision(place, mid, city)) hi = mid;
        else lo = mid;
        if(lo+1 == hi) break;
    }
    return hi;
}
int main()
{
    int t, n, k, l, g, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n ,&k);
        L = M = G = vector<int>(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&l, &m ,&g);
            L[i] = l;
            M[i] = m;
            G[i] = g;
        }
        printf("%d\n",opt(n, k));
    }
}