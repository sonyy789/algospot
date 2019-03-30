#include <cstdio>
#include <algorithm>
using namespace std;
int t, z, size, a, b, ans;
int A[10001];
int main(){
    int i, j;
    A[1] = 1;
    for(i = 2; A[i-1] < 10000; i++) A[i] = A[i-1]+(i-1);
    size = i-2;
    scanf("%d", &t);
    for(z = 1; z <= t; z++){
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        int *aa = upper_bound(A+1, A+1+size, a);
        int *bb = upper_bound(A+1, A+1+size, b);
        int ay = (aa-(A+1)), by = (bb-(A+1));
        int ax = (a-A[ay]+1), bx = (b-A[by]+1);
        if(ay==by) ans = abs(bx-ax);
        else if(ax < bx) ans = by-ay+max(0, bx-ax-(by-ay));
        else ans = by-ay+ax-bx;
        printf("#%d %d\n", z, ans);
    }
}