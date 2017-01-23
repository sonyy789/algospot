#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, k, a, b;
vector<double> r, c;
bool decision(double x)
{
    vector<double> v(n);
    for(int i = 0; i < n; i++)
        v[i] = c[i]*x-r[i];
    sort(v.begin(), v.end());
    double ret = 0;
    for(int i = n-k; i < n; i++)
        ret += v[i];
    return ret>= 0;
}
double opt()
{
    double lo = 0;
    double hi = 1;
    double mid;
    for(int i = 0; i < 100; i++)
    {
        mid = (lo+hi)/2;
        if(decision(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        r = c = vector<double>(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            r[i] = a, c[i] = b;
        }
        printf("%.10lf\n", opt());
    }
}