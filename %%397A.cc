#include <cstdio>
using namespace std;
int n;
int A[101];
int main(){
   int i, j, a, b, l, r;
   scanf("%d%d%d", &n, &a, &b);
   for(i = 1; i <= n-1; i++){ 
      scanf("%d%d", &l, &r);
      A[l]++, A[r]--;
   }
   A[b]++;
   int over_lap = 0, ans = 0;
   for(i = 0; i <= 100; i++){
      over_lap += A[i];
      ans += (a <= i && i <= b && over_lap == 0);
   }
   printf("%d", ans);
}