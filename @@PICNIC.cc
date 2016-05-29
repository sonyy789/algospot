#include <iostream>
#include <cstring>
using namespace std;
int mem[11][11];
int picnic(int arr2[], int index, int N)
{
    if(index == N-1) return 1;
    int cnt = 0;
    
    if(arr2[index]) cnt += picnic(arr2, index+1, N);
    else
    {
       for(int i = index + 1; i < N; i++)
        {
            if(arr2[i] == 0 && mem[index][i])
            {
                arr2[index] = arr2[i] = 1;
                cnt += picnic(arr2, index+1, N);
                arr2[index] = arr2[i] = 0;
            }
        }
    }
    return cnt;
}
int main()
{
    int T, n, m, x, y;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        memset(&mem, 0, sizeof(mem));
        int *arr = new int[n];
        for(int i = 0; i < m; i++)
        {
            cin>>x>>y, mem[x][y]=mem[y][x]=1;
        }
        cout<<picnic(arr, 0, n)<<"\n";
        delete[] arr;
    }
}