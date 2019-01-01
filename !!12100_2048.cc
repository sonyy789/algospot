#include <cstdio>
#include <vector>
using namespace std;
int n, ans;
int D[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
void solve(vector<vector<int>> B, int cnt, int dir){
    int i, j, x, y, x1 = 0, y1 = 0, x2, y2, setX, setY;
    if(cnt < 0){
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                ans = ans > B[i][j] ? ans:B[i][j];
        return;   
    }
    if(dir == 0) x = 0, y = n+1, setX = 1, setY = -n;
    else if(dir == 1) x = 0, y = 0, setX = 1, setY = n;
    else if(dir == 2) x = n+1, y = 0, setX = -n, setY = 1;
    else if(dir == 3) x = 0, y = 0, setX = n, setY = 1;
    if(dir >= 0){
        for(i = 0; i < n; i++){
            y += setY; x += setX;
            y2 = y; x2 = x;
            x1 = y1 = 0;
            for(j = 0; j < n; j++, y+=D[dir][0], x+= D[dir][1]){
                if(B[y][x] == 0) continue;
                if(x1){
                    if(B[y1][x1] == B[y][x]){
                        int tmp = B[y][x]*2;
                        B[y1][x1] = B[y][x] = 0;
                        B[y2][x2] = tmp; y2 += D[dir][0], x2 += D[dir][1];
                        x1 = 0;
                    }else{
                        int tmp = B[y1][x1];
                        B[y1][x1] = 0; B[y2][x2] = tmp;
                        y2 += D[dir][0], x2 += D[dir][1];
                        y1 = y, x1 = x;
                    }
                }else {y1 = y; x1 = x;}
            }
            if(x1) {int tmp = B[y1][x1]; B[y1][x1] = 0; B[y2][x2] =tmp;}
        }
    }
    for(int i = 0; i < 4; i++)  if(dir != i) solve(B, cnt-1, i);
}
int main(){
    scanf("%d", &n);
    vector<vector<int>> B(n+2, vector<int>(n+2, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &B[i][j]);
    solve(B, 5, -1);
    printf("%d", ans);
}