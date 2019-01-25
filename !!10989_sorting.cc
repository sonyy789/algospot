#include <cstdio>
int i, n, val;
int C[10001];

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &val);
        C[val]++;
    }
    for(i = 1; i <= 10000; i++){
        while(C[i]){
            printf("%d\n", i);
            C[i]--;
        }
    }
}