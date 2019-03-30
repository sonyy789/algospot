#include <cstdio>
char A[12], B[12];
int C[26];
int main(){
    int i, j, t, z;
    C['B'-'A'] = 2;
    C['A'-'A'] = C['D'-'A'] = C['O'-'A'] = C['P'-'A'] = C['Q'-'A'] = C['R'-'A'] = 1;
    scanf("%d", &t);
    for(z = 1; z <= t; z++){
        scanf("%s%s", A+1, B+1);
        for(i = j = 1; C[A[i]-'A'] == C[B[j]-'A'] && A[i] != '\0' && B[j] != '\0'; i++, j++);
        printf("#%d %s\n",z, (A[i]==B[j]&&A[i]=='\0')?"SAME":"DIFF");
    }
}