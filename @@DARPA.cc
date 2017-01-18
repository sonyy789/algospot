#include <cstdio>
#include <vector>
using namespace std;
vector<vector<double>> cache;
vector<double> psum;
int t, n, m;
double darpa(int idx, int rest)
{
    double &ret = cache[idx][rest];
    if(ret) return ret;
    if(rest == 1) { return psum[m-1]-psum[idx-1]; }
    for(int i = idx; i <= m-rest; i++)
    {
        double temp = psum[i] - psum[idx-1];
        ret = max(ret, darpa(i+1, rest-1));
        ret = min(temp, ret);
    }
    return ret;
}
int main()
{
    double input, temp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        cache = vector<vector<double>>(m, vector<double>(n, 0));
        psum = vector<double>(m);
        scanf("%lf", &temp), psum[0] = 0;
        for(int i = 1; i < m; i++)
        {
            scanf("%lf", &input);
            psum[i] = input-temp;
        }
        printf("%.2lf\n", darpa(1, n-1));
    }
}