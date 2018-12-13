#include <cstdio>
#define MAX 100001
int A[MAX], V[MAX], R[MAX];
int main(){
   int t, n, f, cnt, idx, ans;
   scanf("%d", &t);
   while(t--){
      scanf("%d", &n);
      ans = n;
      for(int i = 1; i <= n; i++)
         R[i] = V[i] = 0, scanf("%d", &A[i]);
      f = 0;
      for(int i = 1; i <= n; i++)
         if(!V[i]){
            f++;
            cnt = 0;
            idx = i;
            while(!V[idx]){
               cnt++;
               V[idx] = cnt; R[idx] = f; 
               idx = A[idx];
            }
            if(R[idx] == f) ans -= (cnt-V[idx]+1);
         }
      printf("%d\n", ans);
   }
}