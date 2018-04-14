#include <cstdio>
#include <cmath>
int A[25][25];
int main(){
    int t, n, m, ans;
    scanf("%d", &t);
    for(int z= 1; z <= t; z++){
        scanf("%d %d", &n, &m);
        for(int i= 0; i < n; i++)
            for(int j = 0; j < n; j++) 
                scanf("%d", &A[i][j]);
        ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            bool f = true;
            for(int j = 0; j < n-1; j++){
                if(std::abs(A[i][j]-A[i][j+1]) > 1) {f = false; break;}
                if(A[i][j] > A[i][j+1]){
                    bool flag = false;
                    for(int k = j+1; k <= j+m; k++)
                        if(A[i][j]-1 != A[i][k]) {flag = true; break;}
                    if(flag) { f = false; break;}
                    cnt = -1; j+=(m-1);
                }else if(A[i][j] < A[i][j+1]){
                    if(cnt < m) {f = false; break;}
                    cnt = 0;
                }
                cnt++;
            }
            if(f) ans++;
        }
        for(int j = 0; j < n; j++){
            int cnt = 1;
            bool f = true;
            for(int i = 0; i < n-1; i++){
                if(std::abs(A[i][j]-A[i+1][j]) > 1) {f = false; break;}
                if(A[i][j] > A[i+1][j]){
                    bool flag = false;
                    for(int k = i+1; k <= i+m; k++)
                        if(A[i][j]-1 != A[k][j]) {flag = true; break;}
                    if(flag) { f = false; break;}
                    cnt = -1; i+=(m-1);
                }else if(A[i][j] < A[i+1][j]){
                    if(cnt < m) {f = false; break;}
                    cnt = 0;
                }
                cnt++;
            }
            if(f) ans++;
        }
        printf("#%d %d\n", z, ans);
    }
}