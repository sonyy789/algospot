#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define MAX 11
using namespace std;

typedef struct test{
    int x;
    char name[20];
} node;




int main()
{
    int tmp[MAX] = {0};
    node n1[10], result[10];
    //input
    for(int i = 0; i < 10; i++)
    {
        cin>>n1[i].x>>n1[i].name;
    }
    
    //distribute
    for(int i = 0; i < 10; i++)
    {
        tmp[n1[i].x]++;
    }
    
    //difference
    for(int i = 1; i < 10; i++)
    {
        tmp[i] += tmp[i-1];
    }
    
    for(int i = 9; i >= 0; i--)
    {
        int index = tmp[n1[i].x]--;
        result[index].x = n1[i].x;
        strcpy(result[index].name,n1[i].name); 
    }
    cout<<"result =========================="<<endl;
    for(int i = 1; i < 11; i++)
    {
        cout<<result[i].x<<" "<<result[i].name<<endl;
    }
    
}