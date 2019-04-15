#include <cstdio>
#include <algorithm>
using namespace std;
int n, ans;
int A[20], L[20];
int main(){
   int i, j;
   scanf("%d", &n);
   for(i = 1; i <= n; i++)
      scanf("%d", &A[i]);
   int prev = -1, len = 0;
   for(i = n; i >= 1; i--){
      if(A[i] <= prev) L[i] = ++len;
      else L[i] = len = 1;
      prev = A[i];
   }
   len = n;
   for(len; len > 0 && ans == 0; len>>=1)
      for(i = 1; i <= n && ans == 0; i+=len)
         if(L[i] >= len) ans = len; 
   printf("%d", ans);
}