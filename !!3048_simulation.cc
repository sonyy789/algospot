#include <cstdio>
#include <algorithm>
using namespace std;
char A[30], B[30];
int C[60];
int main(){
    int na, nb, t,i ;
    scanf("%d%d", &na, &nb);
    scanf("%s%s%d", A, B, &t);
    for(i = 0; i < na/2; i++)
        swap(A[i], A[na-1-i]);
    int len = na+nb;
    for(i = 0; i < na; i++) C[i] = 1;
    for(i; i < len; i++) C[i] = -1;
    C[len]=2;
    while(t--){
        for(i = 0; i < len; i++)
            if(C[i] > C[i+1]) swap(C[i], C[i+1]), i++;
    }
    na = nb = 0;
    for(i = 0; i < len; i++)
        printf("%c", C[i]>0?A[na++]:B[nb++]);
}