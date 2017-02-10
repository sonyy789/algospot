#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> cache; 
vector<string> arr;
void update(int a, int b, int idx, int m)
{
    if(idx >= m) return;
    if(a == b)
    { 
        for(int i = idx; i < arr[a].size(); i++)
            if(!cache[i].first)
            {
                cache[i].first = 1;
                cache[i].second = a;
            }
        return;
    }
    for(int i = a; i <= b; i++)
    {
        if(arr[i][idx] == '\0') continue; 
        int same = i;
        while(same <= b)
        {
            if(arr[i][idx] != arr[same][idx]) break;
            same++;
        }
        if(cache[idx].first < same-i)
        {
            cache[idx].first = same-i;
            cache[idx].second = same-1;
        }
        update(i, same-1, idx+1, m);
        i = same-1;
    }
}
int main()
{
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cache.clear(), arr.clear();
        arr = vector<string>(n);
        cache = vector<pair<int, int>>(n);
        int idx = 1;
        for(int i = 0; i < n; i++) cin>>arr[i];
        update(0, n-1, 0, m);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j <= i; j++)
                cout<<arr[cache[i].second][j];
            cout<<"\n";
        }
    }
}