#include <iostream>
using namespace std;

int self_seq(int arr2[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int cnt  = 0;
        for(int j = 0; j < size; j++)
        {
            if(i == arr2[j]) cnt++;
        }
        if(arr2[i] != cnt ) return 0;
    }
    
   for(int i = 0; i < size; i++)
    {
       cout<<arr2[i]<<" ";
    }cout<<endl;
}


int perm_rep(int set[], int n, int index, int sum)
{
    if(sum > n) return 0; // sum that overing n(=size) is pruning1
    if(index == n)
    {
        self_seq(set, n);
        return 0;
    }
    
    for(int i = 0; i < n; i++)
    {
        set[index] = i;
        // pruning2
          for(int i = 0; i < index; i++)
            {
                int count  = 0;
               for(int j = 0; j < index; j++)
             {
                 if(i == set[j]) count++;
             }if( count > set[i]) return 0;
             
    }
        
        if(index == 0 && index ==1) sum+=i;
        perm_rep(set, n, index + 1, sum);
    }
}
int main()
{
    int arr[100] = { 0 };
    int n;
    cin>>n;
    for(int i = 0; i < n; i ++)
    {
        arr[i] = i;
    }
    perm_rep(arr, n, 0, 0);
}
