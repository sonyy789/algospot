#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;
int cnt_func(int set[], int N, int M)
{
    int tmp[MAX+1], value = 0;
    memset(&tmp, 0, sizeof(tmp));
    for(int i = 0; i < N; i++)
        tmp[set[i]]++;
    for(int i = MAX; i > 0; i--)
    {
        while(tmp[i]--)
        {
            tmp[i-1]++;
            value += i;
            if((--M) == 0) return value;
        }
    }
}
int main()
{
    int T, N, M;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        int *arr = new int[N];
        for(int i = 0; i < N; i++)
            cin>>arr[i];
        cout<<cnt_func(arr, N, M)<<"\n";
        delete[] arr;
    }
}