#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int max(int a, int b) {return a>b?a:b;}
int main(){
    short in[501];
    int n, cost[501], result[501], a, b;
    scanf("%d",&n);
    vector<vector<int>> edge(n+1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a); b = 1;
        cost[i] = a; result[i] = in[i] = 0;
        while(1){
            scanf("%d", &b);
            if(b < 0) break;
            edge[b].push_back(i);
            in[i]++;
        }
    }
    queue<int> q;
    while(1){
        for(int i = 1; i <= n; i++)
            if(in[i] == 0) q.push(i), in[i] = -1;
        if(q.empty()) break;
        while(!q.empty()){
            int curr = q.front();
            result[curr] += cost[curr];
            q.pop();
            for(int i = 0; i < edge[curr].size(); i++){
                int idx = edge[curr][i];
                result[idx] = max(result[idx], result[curr]);
                in[idx]--;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", result[i]);
}