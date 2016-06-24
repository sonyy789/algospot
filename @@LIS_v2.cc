#include <iostream>
#include <cstring>
using namespace std;
int mem[501];
int result2 = 1;
int lis(int set[], int N, int index)
{
    if(index == N) return 0;
    if(mem[index]) return mem[index];
    int result = 1;
    for(int i = index+1; i < N; i++)
        if(set[index] < set[i])
        {
            result = max(result, lis(set, N, i)+1);
            result2 = max(result, result2);
        }
    if(set[index] > set[index+1])
        result2 = max(result2, lis(set, N, index+1));
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
        result2 = 1;
        memset(&mem, 0, sizeof(mem));
        for(int i = 0; i < N; i++)
            cin>>arr[i];
        lis(arr, N, 0);
        cout<<result2<<"\n";
        delete[] arr;
    }
}