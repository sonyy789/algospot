#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int A[3][21];
int W[10][10]; 
bool check[10];
bool solve(){
    int a, b, c, win[3] = {0,0,0}, idx[3] = {1,1,1};
    a=0, b=1, c=2;
    while(1){
        if((a > 21 || b > 21)||(a == 0 && idx[a] > n)||(b == 0 && idx[b] > n)) return false;
        int val = W[A[a][idx[a]]][A[b][idx[b]]];
        if(val == 2 || (val == 1 && a > b)){ 
            win[a]++;
            if(win[a] == k) return a == 0;
            swap(b,c);
        }else{ 
            win[b]++;
            if(win[b] == k) return b == 0;
            swap(a,b); swap(b,c);
        }
        idx[a]++; idx[c]++;
    }
}
bool perm(int idx){
    if(idx == n+1){
        if(solve()) return true;
        return false;
    }
    for(int i = 1; i <= n; i++){
        if(check[i]) continue;
        check[i] = true;
        A[0][idx] = i;
        if(perm(idx+1)) return true;
        check[i] = false;
    }
    return false;
}
int main(){
    int i, j;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) scanf("%d", &W[i][j]);
    for(i = 1; i <= 20; i++) scanf("%d", &A[1][i]);
    for(i = 1; i <= 20; i++) scanf("%d", &A[2][i]);
    if(n < k) {printf("0"); return 0;}
    printf("%d", perm(1)?1:0);
}