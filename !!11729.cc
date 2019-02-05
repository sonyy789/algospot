#include <cstdio>
using namespace std;
void solve(int n, int a, int b, int c){
    if(n == 1){
        printf("%d %d\n", a, b);
        return;
    }
    solve(n-1,a,c,b);
    solve(1,a,b,c);
    solve(n-1,c,b,a);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n)-1);
    solve(n, 1, 3, 2);
}