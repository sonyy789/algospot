#include <cstdio>
int n;
char ans[81];
bool solve(int idx){
    if(idx == n){
        printf("%s", ans);
        return true;
    }
    int halfLen = (idx+1)/2;
    for(int i = 0; i < 3; i++){
        bool f1 = false;
        ans[idx] = '1'+i;
        for(int j = 1; j <= halfLen; j++){
            bool f2 = true;
            for(int k = 0; k < j; k++){
                if(ans[idx-j-k] != ans[idx-k]) {f2 = false; break;}
            }
            if(f2){f1 = true; break;}
        }
        if(f1) continue;
        if(solve(idx+1)) return true;
    }
    return false;
}
int main(){
    scanf("%d", &n);
    solve(0);
}