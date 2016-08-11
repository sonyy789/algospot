#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <unistd.h>
using namespace std;
int stat = 0;
int WEIRD(int set[], int idx, int N, int sum)
{
    if(N == 0 | sum == N) 
    {
        stat = 1;
        return 0;
    }
    if(N < 0 | idx < 0 | stat | sum < N) return 1;
    return WEIRD(set, idx-1, N, sum-set[idx]) & WEIRD(set, idx-1, N-set[idx], sum-set[idx]);
}
int main()
{
    int T, N, idx, sum, arr[200]; // N : 2~ 500000
    cin>>T;
    while(T--)
    {
        cin>>N;
        stat = 0;
        memset(&arr, 0, sizeof(arr));
        sum = arr[0] = idx = 1;
        double tmp = sqrt(N);
        
        for(int i = 2; i < tmp; i++)
            if( N%i == 0 )
                arr[idx++] = i, arr[idx++] = N/i, sum += (i+N/i);
        if(tmp == (int)tmp)
            arr[--idx] = 0, sum -= tmp;
        if( WEIRD(arr, idx, N, sum) & sum > N )
            cout<<"weird\n";
        else
            cout<<"not weird\n";
    }
}
// 498960 약수 200개 498960 제외시 199 개