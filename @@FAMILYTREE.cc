#include <cstdio>
#include <vector>
using namespace std;
vector<int> arr;
int find_parent(int idx1, int idx2, vector<int> &visited)
{
    int cnt = 0;
    while(idx1 != -1)
    {
        if(visited[idx1] >= 0) return cnt+visited[idx1]; // only resb
        visited[idx1] = cnt;
        cnt++;
        idx1 = arr[idx1];
        if(idx1 == idx2) return cnt; //resa or resb
    }
    return -cnt+1; // resa;
}
int main()
{
    int t, n, q, input;
    scanf("%d", &t);
    while(t--)
    {
        arr.clear();
        scanf("%d%d", &n, &q);
        arr = vector<int>(n);
        arr[0] = -1;
        for(int i = 1; i < n; i++)
            scanf("%d", &arr[i]);
        while(q--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            vector<int> visited(n, -1);
            int resa = find_parent(a, b, visited);
            if(resa > 0) { printf("%d\n", resa); continue; } 
            int resb = find_parent(b, a, visited);
            printf("%d\n", resb);
        }
    }
}