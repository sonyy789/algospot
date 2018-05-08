#include <cstdio>
#include <stack>
using namespace std;
int n, minVal = 101, maxVal = 0;
int A[101][101];
bool visit[101][101];
void dfs(int y, int x, int l){
    stack<pair<int, int>> st;
    st.push(make_pair(y,x));
    visit[y][x] = true;
    while(!st.empty()){
        y = st.top().first;
        x = st.top().second;
        st.pop();
        if(x-1>=0 && !visit[y][x-1] && A[y][x-1] > l) visit[y][x-1] = true, st.push(make_pair(y,x-1));
        if(y-1>=0 && !visit[y-1][x] && A[y-1][x] > l) visit[y-1][x] = true, st.push(make_pair(y-1,x));
        if(x+1 < n && !visit[y][x+1] && A[y][x+1] > l) visit[y][x+1] = true, st.push(make_pair(y,x+1));
        if(y+1 < n && !visit[y+1][x] && A[y+1][x] > l) visit[y+1][x] = true, st.push(make_pair(y+1,x));
    }
}
int dfsAll(int limit){
    int ret = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) visit[i][j] = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!visit[i][j] && A[i][j] > limit) dfs(i,j, limit), ret++;
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
            minVal = minVal<A[i][j]?minVal:A[i][j];
            maxVal = maxVal>A[i][j]?maxVal:A[i][j];
        }
    int ans = 1;
    for(int i = minVal; i <= maxVal; i++){
        int temp = dfsAll(i);
        ans = ans>temp?ans:temp;
    }
    printf("%d\n", ans);
}