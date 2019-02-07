#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, i, j, a, b, s, e, zero = 2e9+1;
int A[100001];
int main(){
   scanf("%d", &n);
   for(i = 1; i <= n; i++)
        scanf("%d", &A[i]);
   sort(&A[1], &A[n+1]);
   s = 1, e = n;
   while(s < e){
       int sum = A[s]+A[e];
       if(zero > abs(sum)){
           zero = abs(sum);
           a = A[s], b = A[e];
       }
       if(sum > 0) e--;
       else if(sum < 0) s++;
       else break;
   }
   printf("%d %d\n", a, b);
}