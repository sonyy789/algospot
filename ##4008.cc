#include <cstdio>
#include <algorithm>
using namespace std;
int t, tc, n, min_val, max_val;
int num[13], op_cnt[5], op[13];
void solve(int idx){
    int i;
    if(idx == n){
        int val = num[1];
        for(i = 1; i < n; i++){
            if(op[i] == 1) val += num[i+1];
            else if(op[i] == 2) val -= num[i+1];
            else if(op[i] == 3) val *= num[i+1];
            else val /= num[i+1];
        }
        max_val = max(max_val, val);
        min_val = min(min_val, val);
        return;
    }
    for(i = 1; i <= 4; i++){
        if(op_cnt[i] == 0) continue;
        op[idx] = i; op_cnt[i]--;
        solve(idx+1);
        op_cnt[i]++;
    }
}
int main(){
    int i;
    scanf("%d", &t);
    for(tc = 1; tc <= t; tc++){
        min_val = 2e9, max_val = -2e9;
        scanf("%d", &n);
        for(i = 1; i <= 4; i++) scanf("%d", &op_cnt[i]);
        for(i = 1; i <= n; i++) scanf("%d", &num[i]);
        solve(1);
        printf("#%d %d\n", tc, max_val-min_val);
    }
}