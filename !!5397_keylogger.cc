#include <cstdio>
#define MAX 1000001
int main(){
    int l;
    char L[MAX], R[MAX], S[MAX];
    scanf("%d", &l);
    while(l--){
        scanf("%s", S);
        int idxL = -1, idxR = -1, i =0;
        while(S[i] != '\0'){
            if(S[i]=='<'){
                if(idxL >= 0) R[++idxR] = L[idxL--];
            }else if(S[i] == '>'){
                if(idxR >= 0) L[++idxL] = R[idxR--];
            }else if(S[i] == '-'){
                if(idxL >= 0) idxL--;
            }else{
                L[++idxL] = S[i];
            }
            i++;
        }
        for(int i = 0; i <= idxL; i++) printf("%c",L[i]);
        for(int i = idxR; i>=0; i--) printf("%c",R[i]);
        printf("\n");
    }
}