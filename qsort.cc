#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void swap(unsigned int set2[], unsigned int a, unsigned int b)
{
    unsigned int tmp = set2[a];
    set2[a] = set2[b];
    set2[b] = tmp;
}

unsigned int partition(unsigned int set[], unsigned int len)
{
    unsigned int ran = rand()%len;
    swap(set, 0, ran);
    unsigned int cnt = 0;
    for(unsigned int i = 1; i < len; i++)
    {
        if( set[0]>set[i] ) swap(set, ++cnt, i);
    }
    swap(set, 0, cnt); 
    return cnt + 1;
}

void qsort( unsigned int set2[],  unsigned int len)
{
    if(len <= 1) return;
    
    unsigned int p = 0;
    p = partition(set2,len);
    qsort(set2, p );
    qsort(set2 + p, len - p);
}

int main()
{
    clock_t begin, end;
    srand((unsigned int)time(NULL));
    unsigned int arr[100000] = {0};
    //array random value
    for(unsigned int i = 0; i <100000; i++)
    {
        arr[i] = rand()%10;
    }
    /*//단조감소수열
    int cnt = 100000;
    for(int i = 0; i < 100000; i++)
    {
        arr[i]=cnt--;
    }*/
    begin = clock();
    qsort(arr, 100000);
    end = clock();
    cout<<"Time unsigned interval is :" << (float)(end - begin)/CLOCKS_PER_SEC<<endl;
    
    /*
    qsort(arr, 100);
    
    for(unsigned int i = 0 ; i < 100; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    */
    
}

//qsort using by recursion
