#include <cstdio>
#include <algorithm>
using namespace std;
int c, n, m;
int A[101], B[101];
int main(){
    int i, j;
    scanf("%d", &c);
    while(c--){
        scanf("%d",&n);
        for(i = 1; i <= n; i++) scanf("%d", &A[i]);
        for(i = 1; i <= n; i++) scanf("%d", &B[i]);
        sort(A+1, A+1+n); sort(B+1, B+1+n);
        i = j = 1;
        while(i <= n && j <= n){
            if(A[i]<=B[j]) i++, j++;
            else j++;
        }
        printf("%d\n", i-1);
    }
}