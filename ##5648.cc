#include <cstdio>
#include <cstring>
#define BASE 2001
#define COLLISION -10001
#define DISABLE 10001
using namespace std;
struct Atom{
    int y, x, dir, k;
};
int map[4002][4002], map_list[1001][2];
int t, z, n;
float D[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
Atom A[1001];
int main(){
    int i, j ;
    scanf("%d", &t);
    for(z=1;z<=t;z++){
        int ans = 0;
        scanf("%d", &n);
        for(i = 1; i <= n; i++){
            scanf("%d%d%d%d",&A[i].x,&A[i].y,&A[i].dir,&A[i].k);
            A[i].x <<= 1, A[i].y <<= 1;
        }
        while(n){
            int n_idx = 0, map_idx = 0;
            for(i = 1; i <= n; i++){
                int ny = A[i].y+D[A[i].dir][0], nx = A[i].x+D[A[i].dir][1];
                if(ny < -2000 || nx < -2000 || ny > 2000 || nx > 2000) {A[i].x = DISABLE; continue;}
                A[i].y = ny, A[i].x = nx;
                if(map[BASE+ny][BASE+nx] > 0){
                    A[map[BASE+ny][BASE+nx]].x = COLLISION;
                    map[BASE+ny][BASE+nx] = A[i].x = COLLISION;
                }else if(map[BASE+ny][BASE+nx] < 0) A[i].x = COLLISION;
                else map[BASE+ny][BASE+nx] = i, map_list[++map_idx][0] = BASE+ny, map_list[map_idx][1] = BASE+nx;
            }
            for(i = 1; i<= map_idx; i++)
                map[map_list[i][0]][map_list[i][1]] = 0;
            for(i = 1; i <= n; i++){
                if(A[i].x == DISABLE);
                else if(A[i].x == COLLISION) ans += A[i].k;
                else A[++n_idx] = A[i];
            }
            n = n_idx;
        }
        printf("#%d %d\n", z, ans);
    }
}