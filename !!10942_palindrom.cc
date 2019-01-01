#include <cstdio>
#include <stack>
using namespace std;
int A[2002], dp[2001][2001];
int main(){
    int n, m, s, e;
    scanf("%d", &n);
    stack<pair<int, int>> st;
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]), st.push({i,1});
    for(int i = 1; i <= n-1; i++)
        if(A[i] == A[i+1]) st.push({i,2});
    while(!st.empty()){
        int s = st.top().first
        int len = st.top().second;
        st.pop();
        dp[s][s+len-1] = 1;
        if(s-1 > 0 && s+len <=n && A[s-1]==A[s+len]) st.push({s-1, len+2});
    }
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
}