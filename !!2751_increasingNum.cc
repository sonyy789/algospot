#include <cstdio>
#define MAX 1000000
int i, n, a, A[MAX*2+1];
int main(){
   for(scanf("%d",&n);n;n--)
      scanf("%d",&a), A[a+MAX]=1;
   for(i = 0; i <= 2*MAX; i++)
      if(A[i]) printf("%d\n", i-MAX);
}