#include <iostream>
#include <vector>
#include <limits>
#define MOD 1000000000
using namespace std;
vector<int> arr(51, 0);
int primefac(int n)
{
    while(n%7 == 0) {n/=7; arr[7]++;}
    while(n%5 == 0) {n/=5; arr[5]++;}
    while(n%3 == 0) {n/=3; arr[3]++;}
    while(n%2 == 0) {n/=2; arr[2]++;}
    arr[n]++;
}
int main()
{
    int n, k;
    vector<long long> mod(5, 0);
    unsigned long long ans = 1;
    cin>>n>>k;
    k = min(k, n-k);
    vector<int> arr2(k,0);
    for(int i = 0; i < k; i++) arr2[i] = n-i;
    for(int i = 2; i <= k; i++) primefac(i);
    for(int i = 2; i <= k; i++)
    {
        if(arr[i] == 0) continue;
        for(int j = 0; j < k; j++)
        {
            if(arr2[j] == 1) continue;
            while(arr[i] && (arr2[j]%i == 0))
            {
                arr2[j] /= i; arr[i]--;
            }
            if(arr[i] == 0) break;
        }
    }
    int cnt = 0;
    mod[0]=1;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j <=cnt; j++)
            mod[j] *= arr2[i];
        for(int j = 0; j <=cnt; j++)
            if(mod[j] > MOD)
            {
                cnt = max(j+1, cnt);
                mod[j+1] += (mod[j]/MOD);
                mod[j]%=MOD;
            }
    }
    for(int i = cnt; i >= 0; i--)
        cout<<mod[i];
    cout<<endl;
}