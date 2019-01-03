#include <cstdio>
#include <cstring>
int main(){
   char A[32], B[32];
   int C[26];
   for(int i = 0; i < 26; i++) C[i] =1e9;
   scanf("%s%s", A, B);
   int a = strlen(A);
   int b = strlen(B);
   for(int i = 0; i < a; i++){
       int idx = A[i]-'A';
       if(C[idx] != 1e9) continue;
       C[idx] = i;
   }
   int x = a, y = 0;
   for(int i = 0; i < b; i++){
       int idx = B[i]-'A';
       if(C[idx] != 1e9 && C[idx] < x){
           x = C[idx];
           y = i;
       }
   }
   for(int i = 0; i < b; i++){
       for(int j = 0; j < a; j++){
           if(i == y) {printf("%c", A[j]); continue;}
           if(j == x) printf("%c", B[i]);
           else printf(".");
       }
       printf("\n");
   }
}