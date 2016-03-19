#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
using namespace std;
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
    if(p < a) part_qsort(set2 + p, len - p, 0, b - p);
    else if(p > b) part_qsort(set2, p, a, b);
    else
    {
        part_qsort(set, p, a, p - 1);
        part_qsort(set + p, len - p, 0, b - p);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int arr[8] = {5,3,8,6,4,2,5,7};
    part_qsort(arr, sizeof(arr)/sizeof(int), 2, 4);
    print(arr,sizeof(arr)/sizeof(int));
}
