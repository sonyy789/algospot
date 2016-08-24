#include <iostream>
#include <limits>
#include <cstring>
#define MIN -1000
using namespace std;
int mem[51][51];
int nbrgame(int set[], int idx, int len)
{
    if(mem[idx][len]) return mem[idx][len];
    if(len == 1)  return set[idx];
    if(len == 0 ) return 0;
    int result = numeric_limits<int>::min();
    result = max(result, -nbrgame(set, idx+2, len-2));
    result = max(result, -nbrgame(set, idx, len-2));
    result = max(result, set[idx]-nbrgame(set, idx+1, len-1));
    result = max(result, set[idx+len-1]-nbrgame(set, idx, len-1));
    
    mem[idx][len] = result;
    return result;
}
int main()
{
    int T, N;
    int arr[51];
    cin>>T;
    while(T--)
    {
        cin>>N;
        memset(&arr, 0, sizeof(arr));
        memset(&mem, 0, sizeof(mem));
        for(int i = 0; i < N; i++)
            cin>>arr[i];
        cout<<nbrgame(arr, 0, N)<<"\n";
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                cout<<mem[i][j]<<" ";
        
        cout<<"\n";    
        }
    }
}