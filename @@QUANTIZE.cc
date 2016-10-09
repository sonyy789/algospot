#include <iostream>
#include <cstring>
#include <limits>
#include <algorithm>
#define MAX 1001
using namespace std;
int arr[101];
int mem[101][101];
int mem2[101][11];
int average(int idx1, int idx2)
{
    if(idx1 == idx2) return 0;
    if(mem[idx1][idx2]) return mem[idx1][idx2];
    double sum = 0;
    for(int i = idx1; i <= idx2; i++)
        sum += arr[i];
    double result = sum/(idx2-idx1+1);
    if(result - (int)result > 0.5) result += 1;
    int value = 0;
    int temp;
    for(int i = idx1; i <= idx2; i++)
        temp = (int)result-arr[i], value += temp*temp;
    mem[idx1][idx2] = value;
    return value;
}
int quantize(int idx, int N, int S)
{
    if(S == 0) return average(idx, N-1);
    if(mem2[idx][S]) return mem2[idx][S]; 
    int temp = numeric_limits<int>::max();
    for(int i = idx; i < N-S; i++)
        temp = min(temp, average(idx, i)+quantize(i+1, N, S-1));
    mem2[idx][S] = temp;
    return temp;
}
int main()
{
    int T, N, S;
    cin>>T;
    while(T--)
    {
        cin>>N>>S;
        memset(&mem, 0, sizeof(mem));
        memset(&mem2, 0, sizeof(mem2));
        for(int i = 0; i < N; i++)
            cin>>arr[i];
        sort(&arr[0], &arr[N]);
        int result = numeric_limits<int>::max();
        for(int i = 0; i < S; i++)
            result = min(result, quantize(0, N, i));
        cout<<result<<"\n";
    }
}