#include <cstdio>
using namespace std;
typedef long long int lld;
char str[52];
int n, idx; 
lld ans;
lld A[52];
int main(){
   int i;
   scanf("%d%s", &n, str+1);
   idx = n; A[1] = 1;
   for(i = 2; i <= n; i++) A[i] = (A[i-1]<<1)+1;
   while(1){
      idx = 1;
      while(idx != n+1 && str[idx] == 'R') {idx++;}
      if(idx == n+1) break;
      for(i = 1; i <= idx; i++) str[i] = 'R';
      ans += (1+A[idx-1]);
   }
   printf("%lld", ans);
}