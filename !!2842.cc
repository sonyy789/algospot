#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
char A[52][52];
int n, sy,sx, rest;
int B[52][52], D[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
bool V[52][52];
bool solve(int y, int x, int low, int high){
    if(B[y][x] < low || B[y][x] > high) return false;
    if(A[y][x] =='K') rest--;
    if(rest == 0) return true;
    bool ret = false;
    for(int i = 0; i < 8; i++){
        int ny = y+D[i][0], nx = x+D[i][1];
        if(V[ny][nx]) continue;
        V[ny][nx] = true;
        ret |= solve(ny, nx, low, high);
    }
    return ret;
}
int main(){
    int kCnt = 0;
    scanf("%d", &n);
    for(int i = 0; i <= n+1; i++){
        V[i][0] = V[0][i] = V[n+1][i] = V[i][n+1] = true;
    }
    vector<int> K;
    for(int i = 1; i <= n; i++){
        scanf("%s", A[i]+1);
        for(int j = 1; j <= n; j++){
            if(A[i][j] == 'P') sy= i, sx=j;
            else if(A[i][j] == 'K') kCnt++;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            scanf("%d", &B[i][j]);
            K.push_back(B[i][j]);
        }
    sort(K.begin(), K.end());
    K.erase(unique(K.begin(), K.end()), K.end());
    int s= 0, e= 0;
    int ans = 2e9;
    while(e < K.size() && s <= e){
        for(int i =1; i <= n; i++)
            for(int j= 1; j <= n; j++)
                V[i][j] = false;
        rest = kCnt;
        if(solve(sy, sx, K[s], K[e])){
            ans = min(ans, K[e]-K[s]);
            s++;
        }else{
            e++;
        }
    }
    printf("%d", ans);
}