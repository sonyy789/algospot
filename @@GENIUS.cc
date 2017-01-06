#include <cstdio>
#include <cmath>
#include <vector>
#define DIV 4
using namespace std;
int T, n, k, m;
vector<double> genius(vector<vector<double>> &set, vector<int> &t)
{
    int size = t.size();
    k -= t[0];
    vector<vector<double>> ret(4, vector<double>(n, 0));
    ret[0] = set[0];
    for(int i = 1; i <= k; i++)
    {
        vector<double> sum(size, 0);
        for(int j = 0; j < size; j++)
        {
            int temp = (DIV+(i-t[j])%DIV)%DIV;
            double curr = ret[temp][j];
            for(int k = 0; k < size; k++)
                sum[k] += curr*set[j][k];
        }
        ret[i%DIV] = sum;
    }
    for(int i = 0; i < size; i++)
        for(int j = 1; j < t[i]; j++)
            ret[k%DIV][i] += ret[((DIV+(k-j)))%DIV][i];
    return ret[k%DIV];
}
int main()
{
    double input;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &k, &m);
        vector<int> minutes(n, 0), like(m, 0);
        vector<vector<double>> per(n, vector<double>(n, 0));
        
        for(int i = 0; i < n; i++) scanf("%d", &minutes[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) scanf("%lf", &per[i][j]);
        for(int i = 0; i < m; i++) scanf("%d", &like[i]);
        
        vector<double> result = genius(per, minutes);
        for(double index : like)
            printf("%.8lf ", result[index]);
        printf("\n");
    }
}
