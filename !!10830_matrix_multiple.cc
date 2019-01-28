#include <cstdio>
#include <vector>
#define MOD 1000
using namespace std;
typedef long long int lld;
vector<vector<int>> B;
int n;
lld b;
void multiple(vector<vector<int>> &X, vector<vector<int>> &Y){
    int i, j, k;
    vector<vector<int>> T(n+1, vector<int>(n+1, 0));
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            for(k = 1; k <= n; k++){
                T[i][j] += X[i][k]*Y[k][j];
                T[i][j] %= MOD;
            }
    X = T;
}
void bi_search(vector<vector<int>> &S, lld exp){
    if(exp == 1) return;
    bi_search(S, exp/2);
    multiple(S,S);
    if(exp&1) multiple(S, B);
}
int main(){
    int i, j;
    scanf("%d%lld", &n, &b);
    vector<vector<int>> A(n+1, vector<int>(n+1));
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++){
            scanf("%d", &A[i][j]);
            A[i][j] %= MOD;
        }
    B = A;
    bi_search(A, b);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}