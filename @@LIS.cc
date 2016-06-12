#include <iostream>
#include <cstring>
using namespace std;
int mem[501];
int lis(int set[], int N, int index)
{
    if(index >= N) return 0;
    if(mem[index]) return mem[index];
    int result = 1;
    for(int i = index+1; i < N; i++)
    {
        if(set[index] < set[i])
            result = max(result, lis(set, N, i)+1);
    }
    mem[index] = result;
    return result;
}
int main()
{  
    int T, N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int *arr =new int[N];
        int sol = 1;
        memset(&mem, 0, sizeof(mem));
        for(int i = 0; i < N; i++)
            cin>>arr[i];
        for(int i = 0; i < N; i++)
            sol = max(sol, lis(arr, N, i));
        cout<<sol<<"\n";
        delete[] arr;
    }
}