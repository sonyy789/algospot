#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define LEN 1314
#define ADD 32768
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int B[LEN][LEN];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
void set(int &y, int &x, int val){
    y = ceil(((float)y+ADD)/50);
    x = ceil(((float)x+ADD)/50);
    B[y][x] = val;
}
int main(){
    int t, n, y, x, sy, sx, addY, addX;
    scanf("%d", &t);
    while(t--){
        memset(&B, 0, sizeof(B));
        scanf("%d", &n);
        scanf("%d%d", &sy, &sx);
        set(sy, sx, 20);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &y, &x);
            set(y, x, 20);
        }
        scanf("%d%d", &y,&x);
        set(y, x, -1);
        queue<pair<int, int>> q;
        q.push({sy, sx});
        while(!q.empty()){
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                sy = cy+dy[i]; sx = sx+dx[i];
                B[sy][sx] = max(B[sy][sx], B[cy][cx]-1);
                if(B[sy][sx]) q.push({sy,sx});
            }
        }
        if(B[y][x] != -1) printf("happy\n");
        else printf("sad\n");
    }
}