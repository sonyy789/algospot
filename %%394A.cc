#include <cstdio>
#include <cmath>
using namespace std;
int A[3];
char str[305], op[2];
int main(){
   int i, a = 0;
   scanf("%s", str+1);
   for(i = 1; str[i] != '\0'; i++){
      if(str[i] != '|') {op[a++] = str[i]; continue;}
      A[a]++;
   }
   bool f = true;
   if(op[0] == '+'){
      int gap = A[0]+A[1]-A[2];
      if(abs(gap) != 2 && abs(gap) != 0) f = false;
      else if(gap > 0){
         a = 0;
         if(A[a] == 1) a++;
         A[a]--; A[2]++;
      }else if(gap < 0) A[0]++, A[2]--;
   }else{
      int gap = A[0]-A[1]-A[2];
      if(abs(gap) != 2 && abs(gap) != 0) f = false;
      else if(gap > 0) A[0]--, A[1]++;
      else if(gap < 0){
         a = 1;
         if(A[a] == 1) a++;
         A[0]++, A[a]--;
      }
   }
   if(f){
      for(i = 1; i <= A[0]; i++) printf("|"); printf("%c",op[0]);
      for(i = 1; i <= A[1]; i++) printf("|"); printf("%c",op[1]);
      for(i = 1; i <= A[2]; i++) printf("|");
   }else printf("Impossible");
}