#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
bool check(int set2[], int len, int value)
{
    int cnt  = 0;
    for(int i = 0; i < len -1; i++)
    {
        if(value == set2[i]) cnt++;
    }
    if(len%2)
    {
        len = len/2;
        if(len < cnt) return true;
        else return false;
    }
    else
    {
        len = len/2;
        if(len <= cnt) return true;
        else return false;
    }
}
int majority(int set[], int len)
{
    if(len == 0) return 0;
    else if(len <= 2) return 1;
    int cnt = 0;
    for(int i = 0; i < len; i+=2 )
    {
        if(set[i] == set[i+1]) set[cnt++] = set[i];
    }
    if(len % 2)
    {
        int cnt2 = 0;
        for(int i = 0; i < cnt; i++)
        {
            if(set[len-1] == set[i]) cnt2++;
        }
        if(check(set, cnt + 1, set[len-1])) return set[len-1];
    }
    majority(set, cnt);
}
int main()
{
    int arr[9] = {4, 1, 1, 1, 4, 4, 1, 4, 4};
    int tmp[9] = {0};
    for(int i = 0; i < 9; i++)
    {
        tmp[i] = arr[i];
    }
    int result = majority(arr, 9);
    if(check(tmp, 10, arr[0])) cout<<arr[0]<<endl;
    else if(check(tmp, 10, arr[1])) cout<<arr[1]<<endl;
    else cout<<"NONE"<<endl;
    
}
