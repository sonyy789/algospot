#include <cstdio>
#include <cstring>
#define MAX 3000
using namespace std;
int n;
char A[3][MAX+2];
int main(){
    memset(&A, -1, sizeof(A));
    register int a = 1, b = 2, c = 0, t, m, idx;
    A[0][MAX] = 0, A[1][MAX] = 0, A[2][MAX] = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        m = 0; idx = MAX;
        while(A[a][idx] != -1 || A[b][idx] != -1 || m){
            A[c][idx] = m+(A[a][idx]>=0?A[a][idx]:0)+(A[b][idx]>=0?A[b][idx]:0);
            m = A[c][idx]>=10?1:0;
            A[c][idx--] %= 10;
        }
        t = c; c = b; b = a; a = t; 
    }
    for(int i = 0; i <= MAX; i++){
        if(A[a][i] == -1) continue;
        printf("%c", A[a][i]+'0');
    }
}