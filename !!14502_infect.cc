#include <cstdio>
#include <stack>
using namespace std;
int A[64], C[64];
int n, m, size, ans = 0;
void dfs(int idx){
    stack<int> st;
    st.push(idx);
    C[idx] = 3;
    while(!st.empty()){
        int curr = st.top();
        int y = curr/m;
        int x = curr%m;
        st.pop();
        if(y-1 >= 0 && !C[curr-m]) C[curr-m] = 3, st.push(curr-m);
        if(x-1 >= 0 && !C[curr-1]) C[curr-1] = 3, st.push(curr-1);
        if(y+1 <  n && !C[curr+m]) C[curr+m] = 3, st.push(curr+m);
        if(x+1 <  m && !C[curr+1]) C[curr+1] = 3, st.push(curr+1);
    }
}
void dfsAll(){
    for(int i = 0; i < size; i++)
        C[i] = A[i];
    for(int i = 0; i < size; i++)
        if(C[i] == 2) dfs(i);
    int cnt = 0;
    for(int i = 0; i < size; i++)
        if(C[i] == 0) cnt++;
    ans = ans>cnt?ans:cnt;
}
void fillOne(int idx, int cnt){
    if(cnt == 3){
        dfsAll();
        return;
    }
    for(int i = idx; i < size; i++)
        if(A[i] == 0){
            A[i] = 1;
            fillOne(idx+1, cnt+1);
            A[i] = 0;
        }
}
int main(){
    scanf("%d %d",&n, &m);
    size = m*n;
    for(int i = 0; i < size; i++)
        scanf("%d", &A[i]);
    fillOne(0, 0);
    printf("%d\n", ans);
}