#include <iostream>
#include <queue>
#include <vector>
#define MOD 20090711
using namespace std;
int main()
{
    int T, N, a, b;
    cin>>T;
    while(T--)
    {
        cin>>N>>a>>b;
        priority_queue<int> lowheap;
        priority_queue<int, vector<int>, greater<int>> highheap;
        long sum = 0;
        long temp = 1983;
        for(int i = 0; i < N; i++)
        {
            if(lowheap.size() == highheap.size())
                lowheap.push(temp);
            else highheap.push(temp);
            if(!lowheap.empty() && !highheap.empty() && lowheap.top() > highheap.top())
            {
                unsigned int a = lowheap.top();
                unsigned int b = highheap.top();
                lowheap.pop(), highheap.pop();
                lowheap.push(b), highheap.push(a);
            }
            sum = (sum +lowheap.top())%MOD;
            temp = (temp*a + b)%MOD;
        }
        cout<<sum%MOD<<"\n";
    }
}