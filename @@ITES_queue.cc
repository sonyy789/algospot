#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int C, N, K;
    cin>>C;
    while(C--)
    {
        queue<unsigned int> arr;
        arr.push(1983);
        unsigned int sum = 0;
        int cnt, idx;
        cnt = idx = 0;
        
        cin>>K>>N;
        while(1)
        {
            if(idx == N-1 && sum < K) break;
            if(sum < K)
            {
                sum += arr.back()%10000+1;
                arr.push(arr.back() * 214013 + 2531011);
                idx++;
                continue;
            }
            else if( sum == K) cnt++;
            sum -= arr.front()%10000+1;
            arr.pop();
        }
        cout<<cnt<<endl;
        for(int i = 0; i < arr.size();i++)
            arr.pop();
    }
}
