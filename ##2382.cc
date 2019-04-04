#include <cstdio>
#include <algorithm>
using namespace std;
struct Point{
    int y, x, k, d;
};
int tc, z, n, m, k;
int D[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
pair<int,int> M[101][101];
Point A[2][1001];
int main(){
    int i, j;
    scanf("%d", &tc);
    for(z=1;z<=tc;z++){
        int a = 0, b = 1;
        scanf("%d%d%d", &n, &m, &k);
        for(i = 1; i <= k; i++){
            scanf("%d%d%d%d", &A[a][i].y, &A[a][i].x, &A[a][i].k, &A[a][i].d);
            A[a][i].d--;
        }
        while(m--){
            int idx_k = 0;
            for(i = 1; i <= k; i++){
                A[a][i].y += D[A[a][i].d][0], A[a][i].x += D[A[a][i].d][1];
                int ny = A[a][i].y, nx = A[a][i].x;
                if(ny < 1 || nx < 1 || ny >= n-1 || nx >= n-1){
                    if(A[a][i].d&1) A[a][i].d--;
                    else A[a][i].d++;
                    A[a][i].k /= 2;
                }
                if(M[ny][nx].first){
                    if(A[a][i].k > M[ny][nx].first) M[ny][nx].first = A[a][i].k, A[b][M[ny][nx].second].d = A[a][i].d;
                    A[b][M[ny][nx].second].k += A[a][i].k;
                }else{
                    M[ny][nx].first = A[a][i].k; M[ny][nx].second = ++idx_k;
                    A[b][idx_k] = A[a][i];
                }
            }
            swap(a,b);
            k = idx_k;
            for(i = 1; i <= k; i++) M[A[a][i].y][A[a][i].x].first = 0;
        }
        int ans = 0;
        for(i = 1; i <= k; i++) ans += A[a][i].k;
        printf("#%d %d\n", z, ans);
    }
}