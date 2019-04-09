#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int lld;
lld n, k;
int main(){
   int i;
   scanf("%lld%lld", &n, &k);
   lld lo = 1, hi = (lld)n*n, ans;
   while(lo <= hi){
      lld mid = (lo+hi)>>1;
      lld cnt = 0;
      for(i = 1; i <= mid/i; i++)
         cnt += min(mid/i, n);
      if(cnt < k) lo = mid+1;
      else ans = mid, hi = mid-1;
   }
   printf("%lld", ans);
}