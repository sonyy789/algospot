#include <cstdio>
#include <queue>
#define MAX 100001
using namespace std;
struct Point{
    int cost, idx;
    bool operator <(const Point &P) const{
        return cost<P.cost;
    }
};
int n, k, i;
int dp[MAX];
int main(){
    scanf("%d%d", &n, &k);
    for(i = 0; i <= MAX; i++) dp[i] = 1e9;
    priority_queue<Point> pq;
    pq.push({0, n});
    dp[n] = 0;
    while(!pq.empty()){
        int idx = pq.top().idx;
        pq.pop();
        if(-pq.top().cost >= dp[k]) continue;
        int next = idx<<1;
        if(idx < k && next < MAX && dp[next] > dp[idx]){
            dp[next] = dp[idx];
            if(next != k) pq.push({-dp[next], next});
        }
        next = idx+1;
        if(idx < k && next < MAX && dp[next] > dp[idx]+1){
            dp[next] = dp[idx]+1;
            if(next != k) pq.push({-dp[next], next});
        }
        next = idx-1;
        if(next >= 0 && dp[next] > dp[idx]+1){
            dp[next] = dp[idx]+1;
            if(next != k) pq.push({-dp[next], next});
        }
    }
    printf("%d", dp[k]);
}