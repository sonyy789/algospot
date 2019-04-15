#include <cstdio>
#include <algorithm>
using namespace std;
int n, p, k;
int main(){
   int i, j;
   scanf("%d%d%d", &n, &p, &k);
   j = min(p+k, n);
   if(p-k > 1) printf("<< ");
   for(i = p-k; i <= j; i++){
      if(i == p) printf("(%d) ", i);
      else if(i >= 1) printf("%d ", i);
   }
   if(p+k < n) printf(">>");    
}