#include <cstdio>
#include <algorithm>
using namespace std;
int n, st_idx;
int A[100001], st[100001];
int main(){
    int i, ans = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    n++; 
    for(i = 0; i < n; i++){
        while(st_idx && A[st[st_idx]] >= A[i]){
            int prev = st[st_idx--];
            int len = st_idx?(i-st[st_idx]-1):i;
            ans = max(ans, len*A[prev]);
        }
        st[++st_idx] = i;
    }
    printf("%d", ans);
}
