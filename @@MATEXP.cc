#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#define MOD 10007
using namespace std;
vector<vector<int>> multimat(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int n = a.size();
    vector<vector<int>> ret(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
            {
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] %= MOD;
            }
    return ret;
}
vector<vector<int>> matexp(vector<vector<int>> set, int n, int p)
{
    if(p == 1) return set;
    if(p == 2) return multimat(set, set);
    vector<vector<int>> ret(n, vector<int>(n));
    ret = matexp(set, n, p/2);
    ret = multimat(ret, ret);
    if(p%2) ret = multimat(ret, set);
    return ret;
}
int main()
{
    int t, n, p;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &p);
        vector<vector<int>> arr(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) cin>>arr[i][j];
        arr = matexp(arr, n, p);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }
    }
}