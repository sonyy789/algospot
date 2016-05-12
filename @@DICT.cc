#include <iostream>
#include <cstring>
#define MAX 1000000000
using namespace std;
int mem[201][201];
void pasc()
{
    memset(&mem, 0, sizeof(mem));
    for(int i = 0; i <= 201; i++)
    {
        mem[i][i] = mem[i][0] = 1;
        for(int j = 1; j < i; j++)
             mem[i][j] = min(MAX, mem[i-1][j] + mem[i-1][j-1]);
    }
}
void dict(int n, int m, int k)
{
    while(n > 0 | m > 0)
    {
        int temp = mem[n+m-1][m];
        if(temp >= k )
            cout<<"a", n--;
        else
            cout<<"b", m--, k -= temp;
        if(k == 0)
        {
            while(m--) cout<<"a";
            while(n--) cout<<"b";
        }
    }
}
int main()
{
    int T, n, m, k;
    pasc();
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        if(mem[n+m][n] < k) 
            cout<<"NONE";
        else
            dict(n, m, k);
        cout<<"\n";
    }
}