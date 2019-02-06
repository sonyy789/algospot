#include <cstdio>
#include <queue>
using namespace std;
int n, k;
bool visit[100001];
int main(){
    int i;
    scanf("%d%d", &n, &k);
    queue<pair<int, int>> q;
    q.push({n, 0});
    int ans1, ans2;
    ans1 = 1e9; ans2 = 0;
    while(!q.empty()){
        int curr = q.front().first;
        int val = q.front().second;
        q.pop();
        visit[curr] = true;
        if(val > ans1) continue;
        if(curr == k && val < ans1){
            ans1 = val;
            ans2 = 1;
        }else if(curr == k && val == ans1) ans2++;
        if(curr == k) continue;
        if(curr < k && (curr<<1) < 100001 && !visit[curr<<1]) q.push({curr<<1, val+1});
        if(curr < k && (curr+1) < 100001 && !visit[curr+1]) q.push({curr+1, val+1});
        if(curr-1 >= 0 && !visit[curr-1]) q.push({curr-1, val+1});
    }
    printf("%d\n%d", ans1, ans2);
}