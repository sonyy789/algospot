#include <cstdio>
#include <stack>
using namespace std;
int n;
int A[500001], B[500001];
int main(){
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) scanf("%d", &A[i]);
    stack<int> st;
    for(i = n; i >= 1; i--){
        while(!st.empty() && A[st.top()] < A[i]){
            B[st.top()] = i;
            st.pop();
        }
        if(A[i] < A[i-1]) B[i] = i-1;
        else st.push(i);
    }
    for(i = 1; i <= n; i++) printf("%d ", B[i]);
}