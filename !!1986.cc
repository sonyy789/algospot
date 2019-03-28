#include <cstdio>
using namespace std;
int n, m, k, r, c;
char A[1001][1001];
int knight[8][2] = {{-2,-1},{-1,-2},{2,-1},{-1,2},{1,-2},{-2,1},{1,2},{2,1}};
int king[8][2] = {{0,-1},{-1,-0},{1,0},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
int main(){
    int i, j, k, l, ans;
    scanf("%d%d", &n, &m);
    ans = n*m;
    for(i = 1; i <= 3; i++){
        scanf("%d", &k);
        ans -= k;
        while(k--){
            scanf("%d%d", &r, &c);
            A[r][c] = i+'0';            
        }
    }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(A[i][j] > 0){
                if(A[i][j] == '1'){
                    for(k = 0; k < 8; k++){
                        int ny = i, nx = j;
                        while(1){
                            ny += king[k][0], nx += king[k][1];
                            if(ny < 1 || nx < 1 || ny > n || nx > m || A[ny][nx] > '0') break;
                            if(A[ny][nx] == 0){
                                A[ny][nx] = '*';
                                ans--;
                            }
                        }
                    }
                }else if(A[i][j] == '2'){
                    for(k = 0; k < 8; k++){
                        int ny = i+knight[k][0], nx = j+knight[k][1];
                        if(ny < 1 || nx < 1 || ny > n || nx > m || A[ny][nx]) continue;
                        A[ny][nx] = '*'; ans--;
                    }    
                }
            }
    printf("%d", ans);
}