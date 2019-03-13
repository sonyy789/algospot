#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, i, j, c, r;
bool C[51], R[51];
char in;
int main(){
    scanf("%d%d", &n, &m);
    r = n, c = m;
    for(i = 0; i < n*m; i++){
        scanf(" %c", &in);
        if(in == 'X'){
            if(!R[i/m]) R[i/m] = true, r--;
            if(!C[i%m]) C[i%m] = true, c--;
        }
    }
    printf("%d", max(r,c));
}