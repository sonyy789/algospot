#include <iostream>
using namespace std;

int perm_rep(int set[], int n, int k, int index)
{
    if(index > n)
    {
        return 0;
    }
    if( k == 0)
    {
        for(int i = index; i < n; i++)
        {
            set[i] = 0;
        }
    
        for(int i =0; i< n; i++)
        {
            cout<<set[i]<<" ";
        }cout<<endl;
        
        return 0;
    }
    
    set[index] = 0;
    perm_rep(set, n, k, index +1);
    set[index] = 1;
    perm_rep(set, n , k - 1 , index + 1 );
}

int main()
{
    int arr[100];
    int n, k;
    cin>>n>>k;
    perm_rep(arr, n, k, 0);
}