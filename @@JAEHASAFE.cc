#include <iostream>
#include <vector>
using namespace std;
void getpi(vector<int> &set, string s)
{
    int size = s.size();
    int i = 0, j = 1;
    while(j < size)
        if(s[i] == s[j]) { set[j] = i+1; i++, j++; }
        else
        {
            if(i) i = set[i-1];
            else j++;
        }
}
int kmpsearch(vector<int> &set, string a, string b)
{
    int i = 0, j = 0;
    int asize = a.size();
    int bsize = b.size();
    while(i < asize && j < bsize)
        if(a[i] == b[j]) { i++; j++; }
        else
        {
            if(j) j = set[j-1]; 
            else i++;
        }
    return i-bsize;
}
int main()
{
    int t, n;
    string a, b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<string> arr(n+1);
        cin>>arr[0];
        vector<int> pi(arr[0].size());
        int ans = 0; int ta = 0; int tb = -1;
        for(int i = 1; i <= n; i++)
        {
            cin>>arr[i];
            getpi(pi, arr[i+tb]);
            ans += kmpsearch(pi, arr[i+ta]+arr[i+ta], arr[i+tb]);
            swap(ta, tb);
            pi.clear();
        }
        cout<<ans<<"\n";
    }
}