#include <cstdio>
#include <queue>
using namespace std;
int n, i, ans, a_idx;
int track[1000001], A[1000001];
int main(){
    scanf("%d", &n);
    queue<pair<int, int>> q;
    q.push({n,0});
    while(!q.empty()){
        int idx = q.front().first;
        int val = q.front().second;
        if(idx == 1){
            ans = val;
            break;
        }
        q.pop();
        if(idx%3==0 && !track[idx/3]) 
            track[idx/3] = idx, q.push({idx/3,val+1});
        if(idx%2==0 && !track[idx/2]) 
            track[idx/2] = idx, q.push({idx/2,val+1});
        if(idx > 1 && !track[idx-1]) 
            track[idx-1] = idx, q.push({idx-1,val+1});
    }
    i = 1;
    while(i){
        A[++a_idx] = i;
        i = track[i];
    }
    printf("%d\n", ans);
    for(a_idx; a_idx> 0; a_idx--) printf("%d ", A[a_idx]);
}