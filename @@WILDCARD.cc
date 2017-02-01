#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool wildcard(string a, string b)
{
    int idx = 0;
    int size1 = a.size(), end = b.size();
    for(int i = 0; i < size1; i++)
    {
        if(a[i] != b[idx])
        {
            if(a[i] == '*')
            {
                while(a[i+1] == '*') i++;
                if( i == size1-1 ) return true; 
                if(a[i+1] == '?')
                {
                    for(int j = idx; j < end; j++)
                        if(wildcard(&a[i+1], &b[j])) return true;
                    return false;
                }
                else
                {
                    for(int j = idx; j < end; j++)
                            if(a[i+1] == b[j])
                            if(wildcard(&a[i+1], &b[j])) return true;
                    return false;
                }
            }
            else if(a[i] == '?') { idx++; continue; }
            else return false;
        }
        idx++;
    }
    if(a.size() != b.size()) return false;
    return true;
}
int main()
{
    int t, n;
    string input, temp;
    cin>>t;
    while(t--)
    {
        cin>>input>>n;
        vector<string> result;
        for(int i = 0; i < n; i++)
        {
            cin>>temp;
            if(wildcard(input, temp)) result.push_back(temp);
        }
        sort(result.begin(), result.end());
        for(string data : result)
            cout<<data<<"\n";
        result.clear();
    }
}