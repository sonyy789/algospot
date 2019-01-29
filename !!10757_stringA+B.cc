#include <cstdio>
#include <cstring>
using namespace std;

char A[10005], B[10005], C[10005];
int len_A, len_B, a, b, c;
int main(){
    scanf("%s%s",A+1,B+1);
    len_A = strlen(A+1);
    len_B = strlen(B+1);
    int len_C = 10004;
    C[--len_C] = '\0';
    while(len_A || len_B){
        a = len_A?(A[len_A--]-'0'):0;
        b = len_B?(B[len_B--]-'0'):0;
        C[--len_C] = '0'+(a+b+c)%10;
        c = a+b+c>=10?1:0;
    }
    if(c) C[--len_C] = c+'0';
    while(C[len_C] != '\0'){
        printf("%c", C[len_C++]);
    }
}