#include <iostream>
using namespace std;
void print_arr(int arr[], int max_size , int size)
{
    int cnt = 0;
    for(int i = 0; i < max_size; i++)
    {
        if(cnt == size)
        {
            cout<<" ";
            cnt = 0;
        }
        cout<<arr[i]<<" ";
        cnt++;
    }cout<<endl;
}
bool check(int temp[], int size, int num)
{
    for(int i = 0; i < size; i++)
    {
        if(temp[i] == num) return true; 
    }
    return false;
}
int perm_rep(int set[], int n, int k, int index, int t)
{

    if(index == t)
    {
        print_arr(set, t, k);
        return 1;
    }
    int result = 1;
    for(int i = 0; i < n; i++)
    {
        result = check(set, index, i);
        if(result) set[index] = i;
        else continue;
        perm_rep(set, n, k, index + 1, t);
    }
}
int main()
{
    int n, k, t;
    int arr[100] = {0};
    cin>>n>>k>>t;
    perm_rep(arr, n, k, 0, t*k);
}

