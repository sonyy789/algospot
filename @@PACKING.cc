#include <iostream>
#include <limits>
#include <vector>
#include <cstring>
using namespace std;
int T, N, W;
int mem[1000][100], volume[100], hope[100];
string name[100];
int packing(int limit , int idx)
{
    if(limit < 0 | idx == N) return 0;
    int &result = mem[limit][idx];
    if(result > -1) return result;
    
    result = packing(limit, idx+1);
    if(limit >= volume[idx])
        result = max(result, packing(limit-volume[idx], idx+1)+hope[idx]);
    return result;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N>>W;
        int W1 = W;
        vector<int> list;
        memset(&mem, -1, sizeof(mem));
        for(int i = 0; i < N; i++)
            cin>>name[i]>>volume[i]>>hope[i];
            
        int tmp = packing(W, 0);
        for(int i = 1; i < N; i++)
            if(tmp != mem[W1][i]) W1 -= volume[i-1], tmp = mem[W1][i], list.push_back(i-1);
        if(tmp > 0) list.push_back(N-1);
        cout<<mem[W][0]<<" "<<list.size()<<"\n";
        for(int i = 0; i < list.size(); i++)
            cout<<name[list[i]]<<"\n";
        list.clear();
    }
}