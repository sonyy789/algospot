#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
struct Point{
    int d, y, x, idx;
    bool operator<(const Point &P){ return d<P.d; }
};
int ans = 1e9;
int O[5], O2[5];
int D[6][3] = {{0,-1,0},{0,1,0},{-1,0,0},{1,0,0},{0,0,1},{0,0,-1}};
int dp[5][5][5];
int B[5][4][5][5];
bool check[5];
unordered_map<int, bool> um;
void dijkstra(int y, int x){
    int i, j, k, ny, nx, nIdx;
    for(k = 0; k < 5; k++)
        for(i = 0; i < 5; i++)
            for(j = 0; j < 5; j++)
                dp[k][i][j] = 1e9;
    queue<Point> q;
    q.push({0, 0, 0, 0});
    dp[O[0]][0][0] = 0;
    while(!q.empty()){
        int y = q.front().y, x = q.front().x, idx = q.front().idx, d = -q.front().d; 
        q.pop();
        for(i = 0; i < 6; i++){
            ny = y+D[i][0], nx = x+D[i][1], nIdx = idx+D[i][2];
            if(nIdx < 0 || nIdx >= 5 || ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || B[O[nIdx]][O2[nIdx]][ny][nx] == 0) continue;
            if(dp[O[nIdx]][ny][nx] > dp[O[idx]][y][x]+1){
                dp[O[nIdx]][ny][nx] = dp[O[idx]][y][x]+1;
                q.push({-dp[O[nIdx]][ny][nx], ny, nx, nIdx});
            }
            if(nIdx == 4 && ny == 4 && nx == 4){
                ans = min(ans, dp[O[4]][4][4]);
                if(ans == 12){
                    printf("12");
                    exit(0);
                }
                return;
            }
        }
    }
}
void perm(int depth){
    int i, j, idx;
    int a, b, c, d, e;
    if(depth == 5){
        int aa = 0, bb = 0;
        for(idx = 0, i = 1, j = 10000; idx < 5; i *= 10, j /= 10,idx++){
            aa += (O[idx]+1)*i;
            bb += (O[idx]+1)*j;
        }
        if(um[aa] || um[bb]) return;
        um[aa] = um[bb] = true;
        for(a=0;a<4;a++){ O2[0] = a; if(B[O[0]][O2[0]][0][0] == 0) continue; 
            for(e=0;e<4;e++){ O2[4] = e; if(B[O[4]][O2[4]][4][4] == 0) continue; 
                for(b=0;b<4;b++){ O2[1] = b;
                    for(c=0;c<4;c++){ O2[2] = c;
                        for(d=0;d<4;d++){ O2    [3] = d; 
                            dijkstra(0,0);
                        }
                    }
                }
            }
        }
        return;
    }
    for(i = 0; i < 5; i++){
        if(check[i]) continue;
        check[i] = true;
        O[depth] = i;
        perm(depth+1);
        check[i] = false;
    }
}
int main(){
    int k, l, i, j;
    for(k = 0; k < 5; k++){
        for(i = 0; i < 5; i++)
            for(j = 0; j < 5; j++)
                scanf("%d", &B[k][0][i][j]);
        for(l = 1; l < 4; l++){
            for(i = 0; i < 5; i++)
                for(j = 0; j < 5; j++)
                    B[k][l][j][5-i-1] = B[k][l-1][i][j];
        }
    }
    perm(0);
    printf("%d", ans==1e9?-1:ans);
}