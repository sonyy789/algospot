#include <cstdio>
int A[27];
int main(){
    int n;
    char fname[31];
    scanf("%d", &n);
    while(n--){
        scanf("%s", fname);
        int idx = fname[0]-'a';
        A[idx]++;
    }
    bool flag = true;
    for(int i = 0; i < 26; i++)
        if(A[i] >= 5) printf("%c",i+'a'), flag = false;
    if(flag) printf("PREDAJA");
}