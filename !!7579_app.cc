#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int A[101], B[101];
    int C[10001] = {0,};
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <=n;i++) scanf("%d", &A[i]);
    for(int i = 1; i <=n;i++) scanf("%d", &B[i]);
    for(int i = 1; i <=n; i++){
        for(int j = 10000; j >= B[i]; j--){
            C[j] = max(C[j], C[j-B[i]]+A[i]);
        }
    }
    for(int i = 1; i <= 10000; i++){
        if(C[i] >=m) {printf("%d",i); break;}
    }
}