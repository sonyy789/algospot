#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int C, N, K;
    cin>>C;
    while(C--)
    {
        deque<unsigned int> arr;
        arr.push_back(1983);
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
                arr.push_back(arr.back() * 214013 + 2531011);
                idx++;
                continue;
            }
            else if(sum == K) cnt++;
            sum -= arr.front()%10000+1;
            arr.pop_front();
        }
        cout<<cnt<<endl;
        arr.clear();
    }
}