#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
using namespace std;
//Using VERSION 1' s check function
bool check(int set3[], int len, int value)
{
    int cnt  = 0;
    for(int i = 0; i < len; i++)
    {
        if(value == set3[i]) cnt++;
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
// Using part_quick sort algorithm
void print(int pr[], int len3)
{
    
    for(int i = 0; i < len3; i++)
    {
        cout<<pr[i]<<" ";
    }cout<<endl;
    
}
void swap(int swp[], int a, int b)
{
    int temp = swp[a];
    swp[a] = swp[b];
    swp[b] = temp;
}

int partition(int set2[], int len2)
{
    int tmp = rand()%len2;
    swap(set2, 0, tmp);
    
    int cnt = 0;
    for(int i = 1; i < len2; i++)
    {
        if(set2[0] > set2[i]) swap(set2, ++cnt, i);
    }
    swap(set2, 0, cnt);
    return cnt + 1;
}

void part_qsort(int set[], int len, int a, int b)
{
    if(len <= 1) return;
    int p = 0;
    p = partition(set, len);
    // 
    if(p < a) part_qsort(set + p, len - p, 0, b - p);
    else if(p > b) part_qsort(set, p, a, b);
    else
    {
        part_qsort(set, p, a, p - 1);
        part_qsort(set + p, len - p, 0, b - p);
    }
}


int main()
{
    int arr[12] = {8, 3, 5, 8, 8, 4, 8, 4, 6, 8, 6, 8};
    int tmp[12] = {0};
    
    for(int i = 0; i < 12; i++)
    {
        tmp[i] = arr[i];
    }
    part_qsort(arr, 12, 1, 6);
    print(arr, 12);
    if(check(tmp, 12, arr[6])) cout<<arr[6]<<endl;
    else cout<<"NONE"<<endl;
}

// using quick sort algo.
// Majority number positioned Middle !! if) sort array