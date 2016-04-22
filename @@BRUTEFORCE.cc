#include <iostream>
#define MOD 1000000007
using namespace std;
long long mul(long long K, long long value)
{
    if(K == 1) return value;
    long long tmp = 1;
    while(1)
    {
        if(K % 2) {
            tmp *= value;
            tmp %= MOD;
        }
        value *= value;
        value %= MOD;
        K /= 2;
        if(K == 1)
        {
            tmp *= value;
            return tmp%MOD;
        } 
    }
}
int main()
{ 

    int T;
    long long A, B, N;
    cin>>T;
    while(T--)
    {
        cin>>A>>B>>N;
        if(N == 1)
        {
            cout<<(B - A + 1)%MOD<<endl;
        }
        else
        {
            long long a1 = mul(A, N);
            long long r1 = mul(B - A + 1, N);
            cout<<( a1 * ((r1-1)/(N-1)) %MOD ) %MOD<<endl;
            cout<<( a1 * (r1 -1) % MOD * mul(MOD -2 , N - 1)) %MOD<<endl;
        }
    }
}
