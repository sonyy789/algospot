#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ko, ru, stat;
int matchorder(int N)
{
    int ret = 0;
    for(int i = 0; i < N; i++)
    {
        int flags = 0;
        for(int j = 0; j < N; j++)
            if(ru[i] <= ko[j] && !stat[j])
            {
                stat[j] = 1, ret++;
                flags = 1;
                break;
            }
        if(flags) continue;
        for(int j = 0; j < N; j++)
            if(!stat[j])
            {
                stat[j] = 1;
                break;
            }
    }
    return ret;
}
int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ru.clear(), ko.clear();
        ru = ko =  stat = vector<int>(n, 0);
        for(int i = 0; i < n; i++) cin>>ru[i];
        for(int i = 0; i < n; i++) cin>>ko[i];
        sort(ko.begin(), ko.end());
        cout<<matchorder(n)<<"\n";
    }
}