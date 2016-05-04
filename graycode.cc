#include <iostream>
using namespace std;
void print(int p[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cout<<p[i];
    }cout<<"\n";
}
void gray(int set[], int index, int N, int stat)
{
    if(index == N)
    {
        print(set, N);
        return;
    }
    int stat2 = 1;
    if(stat) stat2 = 0;
    set[index] = stat;
    gray(set, index + 1, N, 0);
    set[index] = stat2;
    gray(set, index + 1, N, 1);
}
int main()
{
    int N;
    cin>>N;
    int *arr = new int[N];
    gray(arr, 0, N, 0);
    delete[] arr;
}