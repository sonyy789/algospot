#include <cstdio>
long long A[51], a;
int i,j,n,x,y,b,c = 36; char ch;
int main(){
   scanf("%d", &n);
   for(i = 0; i < n; i++){
      for(j = 0; j < 35; j++){
         scanf(" %c", &ch);
         if(ch =='X') A[i] |= ((long long)1<<j);
      }
      for(j = i-1; j >= 0; j--){
         a = A[i]^A[j];
         b = 0;
         while(a){ a &= (a-1); b++;}
         if(b < c) x = j, y = i, c = b;  
      }
   }
   printf("%d %d", x+1, y+1);
}