#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> hot(n), eat(n);
        vector<pair<int, int>> all;
        int sum = 0, ans = 0, temp_sum;
        for(int i = 0; i < n; i++) cin>>hot[i], sum += hot[i];
        temp_sum = sum;
        for(int i = 0; i < n; i++) cin>>eat[i];
        for(int i = 0; i < n; i++) all.push_back(make_pair(eat[i], hot[i]));
        sort(all.begin(), all.end());
        for(int i = n-1; i >= 0; i--)
        {
            sum -= all[i].second;
            int value = sum - all[i].first;
            if(value < 0) ans = max(ans, abs(value));
        }
        cout<<temp_sum+ans<<"\n";
    }
}