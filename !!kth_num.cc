#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int n, k, input;
    priority_queue<int> pq;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        if(pq.size() < k) {pq.push(input); continue;}
        if(input < pq.top())
        {
            pq.pop();
            pq.push(input);
        }
    }
    printf("%d\n", pq.top());
}