#include <cstdio>
int t, d, w, k, ans, in;
bool A[14][21];
int min(int a, int b) {return a<b?a:b;}
int solve(int idx, int depth){
    bool flag = true;
    for(int j = 0; j < w; j++){
        int cnt = 1;
        bool flag2 = false;
        bool prev = A[0][j];
        for(int i = 1; i < d; i++){
            if(prev == A[i][j]) cnt++;
            else prev = A[i][j], cnt = 1;
            if(cnt >= k) {flag2 = true; break;}
        }
        if(flag2) continue;
        flag = false; 
        break;
    }
    if(flag) return depth;
    if(depth == k) return 1e9;
    if(idx == d) return 1e9;
    
    int ret = 1e9;
    bool store[21];
    ret = min(ret ,solve(idx+1, depth));
    for(int j = 0; j < w; j++) {store[j] = A[idx][j]; A[idx][j] = true;}
    ret = min(ret ,solve(idx+1, depth+1));
    for(int j = 0; j < w; j++) {A[idx][j] = false;}
    ret = min(ret, solve(idx+1, depth+1));
    for(int j = 0; j < w; j++) A[idx][j] = store[j];
    
    return ret;
    
}
int main(){
    scanf("%d", &t);
    for(int z = 1; z <= t; z++){
        ans = 1e9;
        scanf("%d %d %d",&d,&w,&k);
        for(int i = 0; i < d; i++)
            for(int j = 0; j < w; j++){
                scanf("%d",&in);
                A[i][j] = in?true:false;
            }
        ans = min(ans, solve(0, 0));
        printf("#%d %d\n", z, ans);
    }
}