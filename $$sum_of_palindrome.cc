#include <cstdio>
#include <algorithm>
using namespace std;
int tc, t, n;
int C[10001], D[10001][3];
int main(){
   int i, j, k;
   for(i = 1; i<10; i++) C[i] = 1, D[i][0] = i;
   for(i = 11; i < 100; i+=11) C[i] = 1, D[i][0] = i;
   for(i = 1; i <= 9; i++)
      for(j = 0; j <= 9; j++){
         int val = i*100+(j*10)+i;
         C[val] = 1, D[val][0] = val;
      }
   for(i = 0; i < 100; i++){
      if(i%10 == 0) continue;
      int val = (i%10)*10+(i/10);
      int tmp = val*100+i;
      C[tmp] = 1, D[tmp][0] = tmp;
   }
   for(k = 1; k <= 2; k++){
      for(i = 1; i <= 10000; i++){
         if(C[i] != 1) continue;
         for(j = i; (i+j) <= 10000; j++){
            if(C[j] == k && C[i+j] == 0){
               C[i+j] = k+1;
               if(k == 1) D[i+j][1] = i, D[i+j][0] = j;
               else{
                  if(i > D[j][0]) D[i+j][0] =i, D[i+j][1] = D[j][0], D[i+j][2] = D[j][1];
                  else if(i > D[j][1]) D[i+j][0] = D[j][0], D[i+j][1] = i, D[i+j][2] = D[j][1];
                  else D[i+j][0] = D[j][0], D[i+j][1] = D[j][1], D[i+j][2] = i;
               }
            }
         }
      }
   }
   scanf("%d", &t);
   for(tc=1;tc<=t;tc++){
      scanf("%d", &n);
      printf("Case #%d\n", tc);
      printf("%d", C[n]);
      for(i = 0; i < C[n]; i++) printf(" %d", D[n][i]);
      printf("\n");
   }
}