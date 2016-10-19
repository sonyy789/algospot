#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#define MAX 225000
using namespace std;
vector<int> shortest[16];
double arr[16][16];
double skip;
int visit[16];
int C, N;
double tsp2(int depth, int curr, double sum)
{
    if(sum >= skip) return 0.0;
    if(depth == N-1)
    {
        if(skip > sum) skip = sum;
        return 1.0;
    }
    visit[curr] = 1;
    for(int i = 0; i < shortest[i].size(); i++)
    {
        int next = shortest[curr][i];
        if(!visit[next])
        {
            visit[next] = 1;
            tsp2(depth+1, i, sum+arr[curr][next]);
            visit[next] = 0;
        }
    }
    visit[curr] = 0;
    return 1.0;
}
void solve()
{
    for(int i = 0; i < N; i++)
        {
            vector<pair<double, int>> list;
            for(int j = 0; j < N; j++)
                if(i != j) list.push_back(make_pair(arr[i][j],j));
            sort(list.begin(), list.end());
            shortest[i].clear();
            for(int j = 0; j < N-1; j++)
                shortest[i].push_back(list[j].second);
            list.clear();
        }
}
int main()
{
    cout.setf(ios_base::floatfield, ios_base::fixed);
    cout.precision(10);
    cin>>C;
    while(C--)
    {
        cin>>N;
        skip = MAX;
        memset(&visit, 0 , sizeof(visit));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin>>arr[i][j];
        solve();
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N-1; j++)
                cout<<shortest[i][j]<<" ";
            cout<<endl;
        }
        for(int i = 0; i < N; i++)
            tsp2(0, i, 0);
        cout<<skip<<"\n";
    }
}