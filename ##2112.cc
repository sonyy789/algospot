#include <cstdio>
#include <algorithm>
using namespace std;
int tc, z, d, w, k, ans, data;
char A[15][25], R[16];
void solve(int cnt, int y){
    if(cnt >= ans) return;
    int i, j;
    //check
    for(j = 1; j <= w; j++){
        int same = 1; bool f = false;
        for(i = 2; i <= d; i++){
            char a = R[i-1]==2?1:(R[i-1]==1)?0:A[i-1][j];
            char b = R[i]==2?1:(R[i]==1)?0:A[i][j];
            if(a == b) same++;
            else same = 1;
            if(same == k) {f = true; break;}
        }
        if(!f) break;
    }
    if(j == w+1){
        ans = min(ans, cnt);
        return;
    }
    //update
    for(i = y+1; i <= d; i++){
        R[i] = 1;
        solve(cnt+1, i);
        R[i] = 2;
        solve(cnt+1, i);
        R[i] = 0;
    }
}
int main(){
    int i,j;
    scanf("%d", &tc);
    for(z=1;z<=tc;z++){
        scanf("%d%d%d", &d, &w, &k);
        ans = d+1;
        for(i = 1; i <= d; i++)
            for(j = 1; j <= w; j++){
                scanf("%d", &data);
                A[i][j] = data;
            }
        if(k == 1) ans = 0;
        else solve(0, 0);
        printf("#%d %d\n", z, ans);
    }
}