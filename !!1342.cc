#include <cstdio>
char A[12];
int alpha[26];
bool visit[12];
int solve(int idx, char prev){
    if(A[idx] == '\0') return 1;
    int ret = 0;
    for(int i = 0; A[i] != '\0'; i++){
        if(visit[i] || A[i] == prev) continue;
        visit[i] = true;
        ret += solve(idx+1, A[i]);  
        visit[i] = false;
    }
    return ret;
}
int fact(int a){
    int ret = 1;
    while(a){
        ret *= a--;
    }
    return ret;
}
int main(){
    int i;
    scanf("%s", A);
    for(i = 0; A[i] != '\0'; i++)
        alpha[A[i]-'a']++;
    int ans = solve(0, '0');
    for(i = 0; i < 26; i++)
        if(alpha[i]) ans /= fact(alpha[i]);
    printf("%d", ans);
}