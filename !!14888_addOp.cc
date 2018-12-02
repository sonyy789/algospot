#include <cstdio>
#define OP 4
int op[OP], A[11], n;
int max, min;
void solve(int idx, int val){
    if(idx == n){
        max = max>val?max:val;
        min = min<val?min:val;
        return;
    }
    for(int i = 0; i < OP; i++){
        if(op[i]){
            op[i]--;
            if(i == 0) solve(idx+1, val+A[idx]); 
            else if(i == 1) solve(idx+1, val-A[idx]);
            else if(i == 2) solve(idx+1, val*A[idx]);
            else solve(idx+1, val/A[idx]);
            op[i]++;
        }
    }
}
int main(){
    min = 1e9+1;
    max = -min;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < OP; i++)
        scanf("%d", &op[i]);
    solve(1, A[0]);
    printf("%d\n%d", max, min);
}