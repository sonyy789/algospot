#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 1000001
using namespace std;
int count[MAX];
int sum(int pos)
{
    pos++;
    int ret = 0;
    while(pos > 0)
    {
        ret += count[pos];
        pos &= (pos-1);
    }
    return ret;
}
void update(int pos, int full)
{
    pos++;
    while(pos < full)
    {
        count[pos]++;
        pos += (pos & -pos);
    }
}
int main()
{
    int t, n, input, size, ans, hi;
    scanf("%d", &t);
    while(t--)
    {
        size = ans = hi = 0;
        scanf("%d", &n);
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            size = max(size, arr[i]);
        }
        size += 2;
        memset(count, 0, sizeof(int)*size);
        for(int i = 0; i < n; i++)
        {
            int here = arr[i];
            hi = max(hi, here);
            update(here, size);
            if(hi < here) continue;
            ans += (sum(hi) - sum(arr[i]));
        }
        printf("%d\n", ans);
    }
}