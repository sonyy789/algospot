#include <cstdio>
#include <cstring>
using namespace std;
int F[1000002], A[1000002];
char T[1000002], P[1000002];
int main(){
    int i, j, tLen, pLen, ans = 0;
    scanf("%[^\n]s", T+1);
    getchar();
    scanf("%[^\n]s", P+1);
    tLen = strlen(T+1), pLen = strlen(P+1);
    //setF
    j = 0;
    for(i = 1; i < pLen; i++){
        while(j&&P[i+1]!=P[j+1]){j = F[j];}
        if(P[i+1] == P[j+1]){
            F[i+1] = ++j;
        }
    }
    //Match
    j = 0;
    for(i = 0; i < tLen; i++){
        while(j&&T[i+1] != P[j+1]){ j = F[j];}
        if(T[i+1] == P[j+1]){ ++j; }
        if(j == pLen) A[ans++] = i-pLen+2;
    }
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++)
        printf("%d\n", A[i]);
}