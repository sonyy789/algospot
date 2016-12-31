#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> prc_prt;
vector<int> stat;
int cache[201];
int solve(int M, int N)
{
    int ret = 0;
    cache[0] = 0;
    for(int i = 1; i <= M; i++)
    {
        int value = 0;
        for(int j = 0; j < N; j++)
        {
            if(stat[j]) continue;
            if(prc_prt[j].first <= i)
                value = max(value, cache[(i-prc_prt[j].first)%201]+prc_prt[j].second);
        }
        cache[i%201] = value;     
        ret = max(ret, value);
    }
    return ret;
}
int main()
{
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        m /= 100;
        prc_prt.clear();
        prc_prt = vector<pair<int, int>>(n);
        for(int i = 0; i < n; i++)
        {
            cin>>prc_prt[i].first>>prc_prt[i].second;
            prc_prt[i].first /= 100;
        }
        stat = vector<int>(n, 0);
        sort(prc_prt.begin(), prc_prt.end());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
            {
                if(stat[j]) continue;
                if((prc_prt[i].first/prc_prt[j].first)*prc_prt[j].second > prc_prt[i].second) stat[i] = 1;
                continue;
            }
        cout<<solve(m, n)<<"\n";
    }
}