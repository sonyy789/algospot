#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct Point{
    int d,y,x;
};
int n, m, p;
int S[10], A[10];
int D[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
char B[1003][1003];
queue<Point> P[2][10];
int main(){
    int i, j, a, b;
    a = 0, b = 1;
    scanf("%d%d%d", &n, &m, &p);
    for(i = 1; i <= p; i++)
        scanf("%d", S+i);
    for(i = 1; i <= n; i++){
        scanf("%s", B[i]+1);
        for(j = 1; j <= m; j++){
            if(B[i][j] == '.' || B[i][j] == '#') continue;
            int idx = B[i][j]-'0'; 
            P[a][idx].push({S[idx],i,j});
        }
    }
    while(1){
        int is_new = 0;
        for(i = 1; i <= p; i++){
            is_new |= P[a][i].size();
            while(!P[a][i].empty()){
                int d = P[a][i].front().d;
                int y = P[a][i].front().y;
                int x = P[a][i].front().x;
                P[a][i].pop();
                if(d == 0) continue;
                for(j = 0; j < 4; j++){
                    int ny = y+D[j][0], nx = x+D[j][1];
                    //printf("\n");
                    if(ny < 1 || nx < 1 || ny > n || nx > m || B[ny][nx] != '.') continue;
                    B[ny][nx] = i+'0';
                    P[a][i].push({d-1, ny, nx}); P[b][i].push({S[i], ny, nx});
                }
            }
        }
        if(!is_new) break;
        swap(a,b);
    }
    
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++){
            if(B[i][j] == '.' || B[i][j] == '#') continue;
            A[B[i][j]-'0']++;
        }
    for(i = 1; i <= p; i++)
        if(A[i]) printf("%d ", A[i]);
}