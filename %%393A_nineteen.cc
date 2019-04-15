#include <cstdio>
char str[102];
int C[26];
int main(){
   int i, n;
   scanf("%s", str+1);
   for(i = 1; str[i] != '\0'; i++) C[str[i]-'a']++;
   for(i = 1, n = 3;(C[19]>=i & C[8]>=i & C[13]>=n & C[4]>=3*i);i++, n+=2);
   printf("%d", i-1);
}