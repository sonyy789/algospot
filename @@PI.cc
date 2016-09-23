#include <iostream>
#include <cstring>
#include <limits>
#include <cmath>
#include <vector>
#define MAX 40000
#define DEFAULT 10
using namespace std;
string input;
int mem[10001];
int strchk(int idx1, int idx2)
{
    int ret1=1, ret2=2, ret3=4, ret4=5;
    int stat, stat2 = input[idx1]-input[idx1+1];
    for(int i = idx1+1; i < idx2; i++)
    {
        stat = input[i]-input[i+1];
        if(stat != 0 | stat2 != 0) ret1 = 0;
        if(abs(stat) != 1 | stat != stat2 ) ret2 = 0;
        if( stat != -stat2 ) ret3 = 0;
        if(stat != stat2) ret4 = 0;
        stat2 = stat;
    }
    if(ret1) return ret1;
    else if(ret2) return ret2;
    else if(ret3) return ret3;
    else if(ret4) return ret4;
    else return DEFAULT;
}
int pi(int N, int idx)
{
    if(mem[idx]) return mem[idx];
    if(N == 2 | N == 1 | N < 0) return MAX;
    if(N == 0)  return 0;
    int ret = 0;
    int tmp = MAX;
    for(int i = 3; i < 6; i++)
        tmp = min(tmp, pi(N-i, idx+i)+strchk(idx, idx+i-1));
    mem[idx] = tmp;
    return ret += tmp;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>input;
        memset(&mem, 0, sizeof(mem));
        cout<<pi(input.size(), 0)<<"\n";
    }
}