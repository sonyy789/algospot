#include <iostream>
#define MAX 2000000000
using namespace std;
int main()
{
    int t;
    long long p, m, n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        p = m*100/n;
        p++;
        long long lo = 0;
        long long hi = MAX+1;
        while(lo+1 != hi) // value of lo always != ans;
        {
            long long mid = lo + (hi-lo)/2;
            long long temp = (m+mid)*100/(n+mid);
            if(temp < p) lo = mid;
            else hi = mid;
        }
        if(hi > MAX) { cout<<"-1\n"; continue; }
        cout<<hi<<"\n";
    }
}