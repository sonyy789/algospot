#include <cstdio>
bool visit[10];
int main(){
    int n, S[101], B[101], ans = 0, tmps, tmpb;
    char in[4], hint[101][4];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s %d %d", hint[i], &S[i], &B[i]);
    for(int i = 1; i <= 9; i++){
        visit[i] = true;
        for(int j = 1; j <= 9; j++){
            if(visit[j]) continue; visit[j] = true;
            for(int k = 1; k <= 9; k++){
                if(visit[k]) continue; visit[k] = true;
                bool flag = true; 
                for(int x = 0; x < n; x++){
                    tmps = tmpb = 0;
                    if(i+'0' == hint[x][0]) tmps++;
                    if(j+'0' == hint[x][1]) tmps++;
                    if(k+'0' == hint[x][2]) tmps++;
                    if(i+'0' == hint[x][1] || i+'0' == hint[x][2]) tmpb++;
                    if(j+'0' == hint[x][0] || j+'0' == hint[x][2]) tmpb++;
                    if(k+'0' == hint[x][0] || k+'0' == hint[x][1]) tmpb++;
                    if(tmps != S[x] || tmpb != B[x]) {flag = false; break;}
                }
                if(flag) ans++;
                visit[k] = false;
            }visit[j] = false;
        }visit[i] = false;
    }
    printf("%d\n", ans);
}