#include <cstdio>
#include <algorithm>
using namespace std;
int i, j, k, ans = 1e9, A[6];
int gcd(int a, int b){ return b?gcd(b, a%b):a;}
int main(){
    for(i = 1; i <= 5; i++)
        scanf("%d", A+i);
    for(i = 1; i <= 3; i++)
        for(j = i+1; j <= 4; j++)
            for(k = j+1; k <= 5; k++){
                int t = (A[j]*A[k])/gcd(A[j],A[k]);
                ans = min(ans, (A[i]*t)/gcd(A[i],t));
            }
    printf("%d", ans);
}