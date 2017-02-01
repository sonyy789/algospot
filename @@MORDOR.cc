#include <cstdio>
#include <vector>
#include <limits>
using namespace std;
const int inf = numeric_limits<int>::max();
vector<int> height;
vector<pair<int, int>> arr;
pair<int, int> rmq(int left, int right, int node)
{
    if(left == right)
    {
        arr[node].first = arr[node].second = height[left];
        return arr[node];
    }
    int mid = (left+right)/2;
    arr[node] = rmq(left, mid, node*2+1);
    pair<int, int> temp = rmq(mid+1, right, node*2+2);
    arr[node].first = min(arr[node].first, temp.first);
    arr[node].second = max(arr[node].second, temp.second);
    return arr[node];
}
pair<int, int> query(int start, int end, int left, int right, int node)
{
    if(left > end || right < start) return make_pair(inf, -1);
    if(left <= start && end <= right) return arr[node];
    int mid = (start+end)/2;
    pair<int, int> ret = query(start, mid, left, right, node*2+1);
    pair<int, int> temp = query(mid+1, end, left, right, node*2+2);
    ret.first = min(ret.first, temp.first);
    ret.second = max(ret.second, temp.second);
    return ret;
}
int main()
{
    int t, a, b, N, Q;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &N, &Q);
        height.clear(), arr.clear();
        height = vector<int>(N, 0);
        arr = vector<pair<int, int>>(4*height.size());
        for(int i = 0; i < N; i++)
            scanf("%d", &height[i]);
        rmq(0, N-1, 0);
        while(Q--)
        {
            scanf("%d%d", &a, &b);
            pair<int, int> result = query(0, N-1, a, b, 0);
            printf("%d\n", result.second-result.first);
        }
    }
}