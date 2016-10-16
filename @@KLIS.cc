#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 2000000001
using namespace std;
int arr[501];
int mem[501];
int mem_count[502];
int C, N, K;
vector<pair<int, int>> list;
int lis_count(int idx, int K)
{
    if(mem[idx]) return mem[idx];
    if(idx == N-1) return 1;
    int result = 1;
    long long cnt = 1;
    for(int i = idx+1; i < N; i++)
    {
        if(arr[idx]<arr[i])
        {   
            int temp = lis_count(i, K-1)+1;
            if(result < temp ) result = temp, cnt = mem_count[i];
            else if(result == temp) cnt += mem_count[i];
            cnt = min<long long>((long long)cnt, MAX);
        }
    }
    mem_count[idx] = cnt;
    mem[idx] = result;
    return result;
}
int klis(int length, int idx, int placing)
{
    if(length == 0) return 0;
    int size = list.size();
    for(int i = 0; i < size; i++)
    {
        int temp_index = list[i].second;
        if(temp_index < idx) continue;
        if(mem[temp_index] != length) continue;
        if(arr[temp_index] < arr[idx]) continue;
        
        if(mem_count[temp_index] < placing) placing -= mem_count[temp_index];
        else
        {
            cout<<arr[temp_index]<<" ";
            return klis(length-1, temp_index, placing);
        }
    }
    return 1;
}
int main()
{
    cin>>C;
    arr[-1] = -1;
    while(C--)
    {
        cin>>N>>K;
        //init mem, mem_count
        memset(&mem, 0, sizeof(mem));
        for(int i = 0; i < N; i++)
            mem_count[i] = 1;
        mem[N-1] = 1;
        //input data
        for(int i = 0; i < N; i++)
            cin>>arr[i], list.push_back(pair<int, int>(arr[i], i));
        int result = 1;
        for(int i = N-1; i >= 0; i--)
            result = max(result, lis_count(i, K));
        sort(list.begin(), list.end());
        cout<<result<<"\n";
        klis(result, -1, K);
        cout<<"\n";
        list.clear();
    }
}