#include <cstdio>
#include <cstring>
int main(){
    char A[51], B[51];
    scanf("%s %s", A, B);
    int a = strlen(A);
    int b = strlen(B);
    int ans = 51;
    for(int i = 0; i+a <= b; i++){
        int cnt = 0;
        for(int j = 0; j < a; j++)
            if(A[j] != B[i+j]) cnt++;
        ans = ans < cnt? ans:cnt;
    }
    printf("%d\n", ans);
}