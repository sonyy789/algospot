#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int t, n, m;
struct Point{ int y, x; };
char B[2001][2001];
bool visited[2001][2001];
Point C[4001];
int main(){
    int i, j, z;
    scanf("%d", &t);
    for(z = 1; z <= t; z++){
        memset(&visited, 0, sizeof(visited));
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i++)
            scanf("%s", B[i]+1);
        queue<Point> q;
        q.push({1, 1});
        visited[1][1] = true;
        printf("#%d ", z);
        for(i = 1; i < n+m; i++){
            int c_idx = 0;
            char min_char = 'z'+1;
            while(!q.empty()){
                Point p = q.front();
                q.pop();
                if(min_char < B[p.y][p.x]) continue;
                else if(min_char > B[p.y][p.x]) c_idx = 0;
                min_char = B[p.y][p.x];
                C[++c_idx] = p;
            }
            for(j = 1; j <= c_idx; j++){ 
                if(C[j].y == n && C[j].x == m) continue;
                if(C[j].y < n && !visited[C[j].y+1][C[j].x]) visited[C[j].y+1][C[j].x] = true, q.push({C[j].y+1,C[j].x});
                if(C[j].x < m && !visited[C[j].y][C[j].x+1]) visited[C[j].y][C[j].x+1] = true, q.push({C[j].y,C[j].x+1});
            }
            printf("%c",min_char);
        }
        printf("\n");
    }
}