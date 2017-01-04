#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 10
using namespace std;
int main()
{
    int t, n, size, input;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> s(n);
        vector<vector<int>> r;
        for(int i = 0; i < n; i++)
        {
            vector<int> temp;
            cin>>s[i]>>size;
            for(int i = 0; i < size; i++)
                cin>>input, temp.push_back(input);
            r.push_back(temp);
        }
        for(int i = 0; i < r.size(); i++)
            sort(r[i].begin(), r[i].end());
        int lo = 0;
        int hi = 1000*n + 1;
        for(int i = 0; i < 100; i++)
        {
            if(lo+1 == hi) break;
            int mid = (lo + hi)/2;
            int cnt = 0, flags = 0;
            for(int j = 0; j < r.size(); j++)
            {
                int temp = mid*s[j], sum = 0;
                for(int k = r[j].size()-1; k >=0; k--)
                {
                    sum += r[j][k], cnt++;
                    if(sum >= temp) break;
                }
                if(cnt > MAX_N || (sum/s[j]) < mid ) // over block
                {
                    flags = 1;
                    break;
                }
            }
            if(flags) hi = mid;
            else lo = mid;
        }
        cout<<lo<<"\n";
    }
}