#include <cstdio>
#include <queue>
using namespace std;
int A[51][51];
bool dir[9][4] = {{0,0,0,0},{1,1,1,1}, {1,0,1,0}, {0,1,0,1}, {1,0,0,1}, {0,0,1,1},{0,1,1,0},{1,1,0,0}};
int main(){
    int t, n, m, r, c, l, ans;
    scanf("%d", &t);
    for(int z= 1; z <= t; z++){
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) scanf("%d", &A[i][j]);
            
        queue<pair<int, int>> q[2];
        int flag = 0;
        q[flag].push(make_pair(r,c));
        while(l--){
            while(!q[flag].empty()){
                int y = q[flag].front().first;
                int x = q[flag].front().second;
                q[flag].pop();
                if(A[y][x] == -1) continue;
                if(y-1>= 0 && A[y-1][x] > 0 && (dir[A[y][x]][0] && dir[A[y-1][x]][2])) q[!flag].push(make_pair(y-1,x));
                if(x-1>= 0 && A[y][x-1] > 0 && (dir[A[y][x]][1] && dir[A[y][x-1]][3])) q[!flag].push(make_pair(y,x-1));
                if(y+1< n && A[y+1][x] > 0 && (dir[A[y][x]][2] && dir[A[y+1][x]][0])) q[!flag].push(make_pair(y+1,x));
                if(x+1< m && A[y][x+1] > 0 && (dir[A[y][x]][3] && dir[A[y][x+1]][1])) q[!flag].push(make_pair(y,x+1));
                A[y][x] = -1;
            }
            flag = !flag;
        }
        ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(A[i][j] == -1) ans++;
        printf("#%d %d\n", z, ans);
    }
}