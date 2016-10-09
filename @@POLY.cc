#include <iostream>
#include <cstring>
#define MOD 10000000
using namespace std;
unsigned int mem[101][101];
unsigned int poly(unsigned int N, unsigned int preleng, unsigned int depth)
{
    if(N == 0) return 1;
    if(mem[N][preleng]) return mem[N][preleng]%MOD;
    unsigned int result = 0;
    unsigned int temp;
    for(unsigned int i = 1; i <= N; i++)
    {
        temp = poly(N-i, i, depth+1);
        if(depth) temp *= (preleng+i-1);
        result += temp%MOD;
    }
    mem[N][preleng] = result%MOD;
    return result%MOD;
}
int main()
{
    memset(&mem, 0, sizeof(mem));
    unsigned int T, N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        cout<<poly(N, 0, 0)<<"\n";
    }
    
}