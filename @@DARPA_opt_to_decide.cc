#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<double> arr;
int t, n, m;
bool decide(double plus, int camera)
{
    double limit = -1;
    int cnt = 0;
    for(int i = 0; i < m; i++)
        if(limit <= arr[i])
        {
            ++cnt;
            limit = arr[i]+plus;
        }
    return cnt >= camera;
}
double opt(int place, int camera)
{
    double lo = 0;
    double hi = 241;
    double mid;
    for(int i = 0; i < 100; i++)
    {
        mid = (lo+hi)/2;
        if(decide(mid, camera)) lo = mid;
        else hi = mid;
    }
    return lo;
}
int main()
{
    double input, temp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        arr = vector<double>(m);
        for(int i = 0; i < m; i++) scanf("%lf", &arr[i]);
        printf("%.2lf\n", opt(m, n));
    }
}