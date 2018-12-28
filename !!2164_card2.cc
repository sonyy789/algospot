#include <cstdio>
int main(){
    int i, nextI, a, tn, n, A[500001] = {0,};
    bool f = true;
    scanf("%d", &n);
    tn = n; i = 1, a = 2;
    while(tn != 1){
        if(f) nextI = i+(a/2);
        else nextI = i, i += (a/2);
        for(i; i <= n && tn; i +=a) A[i] = 1, tn--;
        if(tn == 1) {i = nextI; break;}
        if(tn == 0) {i -= a; break;}
        int val = i-a/2;
        if(val <= n && A[val] == 0) f = true;
        else f = false;
        i = nextI; a *= 2;
    }
    printf("%d", i);
}