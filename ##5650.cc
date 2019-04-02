#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int t, z, n, ans, sy, sx;
int A[101][101];
int C[6][4] = {{0,0,0,0},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1}};
int D[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int W[10][2];
map<pair<int,int>, pair<int,int>> mp;
int solve(int y, int x, int dir){
    int ret = 0;
    do{
        if(y < 1 || x < 1 || y > n || x > n){
            y -= D[dir][0], x -= D[dir][1];
            dir = (dir+2)%4; ret++;
        }else if(0 < A[y][x] && A[y][x] < 6){
            dir = C[A[y][x]][dir]; ret++;
            y += D[dir][0], x += D[dir][1];
        }else if(5 < A[y][x]){
            int ty = y, tx = x;
            y = mp[{ty, tx}].first+D[dir][0], x = mp[{ty, tx}].second+D[dir][1];
        }else y += D[dir][0], x += D[dir][1];
    }while((sy != y || sx != x)&&A[y][x] != -1);
    return ret;
}
int main(){
    int i, j, k;
    scanf("%d", &t);
    for(z=1;z<=t;z++){
        ans = 0;
        mp.clear();
        memset(&W, 0, sizeof(W));
        
        scanf("%d", &n);
        for(i = 1; i <= n; i++) 
            for(j = 1; j <= n; j++){
                scanf("%d", &A[i][j]);
                if(6 <= A[i][j] && A[i][j] <= 10){
                    int idx = A[i][j];
                    if(W[idx-6][0]){ 
                        mp[{W[idx-6][0], W[idx-6][1]}] = {i,j};
                        mp[{i,j}] = {W[idx-6][0], W[idx-6][1]};
                    }else W[idx-6][0] = i, W[idx-6][1] = j;
                }
            }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++){
                if(A[i][j]) continue;
                sy = i, sx = j;
                for(k = 0; k < 4; k++)
                    ans = max(ans, solve(i, j, k));
            }
        printf("#%d %d\n", z, ans);
    }
}
