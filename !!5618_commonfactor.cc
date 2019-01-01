#include <cstdio>
int f(int a, int b){ return b?f(b,a%b):a; }
int main(){
    int A[3], n, l;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) scanf("%d", &A[i]);
    l = f(A[0], A[1]); if(n==3) l = f(l, A[2]);
    for(int i = 1; i <= l; i++)
        if(l%i ==0) printf("%d\n", i);
}