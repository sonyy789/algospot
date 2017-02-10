#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct comparator{
    int t;
    vector<int> &group;
    comparator(vector<int> &_group, int _t) : group(_group), t(_t)
    {
        group = _group;
        t = _t;
    }
    bool operator()(int a, int b) 
    {
        if(group[a] != group[b]) return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};
vector<int> suffixsort(const string &s)
{
    int n = s.size();
    int t = 1;
    vector<int> group(n+1);
    for(int i = 0; i < n; i++) group[i] = s[i];
    group[n] = -1;
    vector<int> perm(n);
    for(int i = 0 ; i < n ; i++) perm[i] = i;
    while(t < n)
    {
        comparator cptr(group, t);
        sort(perm.begin(), perm.end(), cptr);
        t *= 2;
        if(t >= n) break;
        vector<int> newgroup(n+1);
        newgroup[perm[0]] = 0; newgroup[n] = -1;
        for(int i = 1; i < n; i++)
            if(cptr(perm[i-1], perm[i]))
                newgroup[perm[i]] = newgroup[perm[i-1]]+1;
            else
                newgroup[perm[i]] = newgroup[perm[i-1]];
        group = newgroup;
    }
    return perm;
}
void commonprefix(vector<int> &set, int a, int b, const string &s)
{
    int k = 0;
    int n = s.size();
    while(a < n && b < n && s[a] == s[b])
    {
        a++, b++, k++;
        set[a]++, set[b]++;
    }
}
int main()
{
    int t, k;
    cin>>t;
    while(t--)
    {
        cin>>k;
        string input;
        cin>>input;
        vector<int> result = suffixsort(input);
        for(int data : result)
            cout<<data<<" ";
        cout<<endl;
        vector<int> ans(result.size());
        /*
        for(int i = 1; i < result.size(); i++)
        {
            commonprefix(ans, result[i], result[i-1], input);
        }*/
    }
    
}