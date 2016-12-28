#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> nadj, size, root, ran;
int find(int k)
{
    if(k == root[k]) return k;
    return root[k] = find(root[k]);
}
int merge(int a, int b)
{
    if(a == -1 || b == -1) return max(a, b);
    a = find(a), b = find(b);
    if(a == b) return a;
    if(ran[a] > ran[b]) swap(a, b);
    if(ran[a] == ran[b]) ran[b]++;
    root[a] = b;
    size[b] += size[a];
    return b;
}
int solve(int n, int w)
{
    int a, b, ret = 0;
    char input[4];
    for(int i = 0; i < w; i++)
    {
        scanf("%s%d%d", input, &a, &b);
        if(ret) continue;
        a = find(a), b = find(b);
        if(input[0] == 'A')
        {
            if(nadj[a] == b) ret = i+1;
            int x = merge(a, b), y = merge(nadj[a], nadj[b]);
            nadj[x] = y;
            if(y != -1) nadj[y] = x;
        }
        else
        {
            if(a == b) ret = i+1;
            int x = merge(a, nadj[b]), y =  merge(b, nadj[a]);
            nadj[x] = y, nadj[y] = x;
        }
    }
    if(ret) return ret;
    for(int i = 0; i < n; i++)
        if(root[i] == i)
        {
            int opp = nadj[i];
            if(i < opp) continue;
            int cursize = size[i];s
            int oppsize = ( opp == -1 ? 0 : size[opp]);
            ret += max(cursize, oppsize);
        }
    return -ret;
}
int main()
{
    int t, n, w;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &w);
        root = vector<int>(n);
        ran = vector<int>(n, 0);
        size = vector<int>(n, 1);
        nadj = vector<int>(n, -1);
        for(int i = 0; i < n; i++) root[i] = i;
        int ans = solve(n, w);
        if(ans > 0) printf("CONTRADICTION AT %d\n", ans);
        else printf("MAX PARTY SIZE IS %d\n", -ans);
    }
}