#include <cstdio>
#include <queue>
#include <cstring>
#define IDX 350
using namespace std;
int t, z, n, m, k;
int D[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int A[800][800];
struct Point{
    int y, x, act, age;
    bool operator < (const Point &P) const{
        return act==P.act?(age<P.age):(act>P.act);
    }
};
int main(){
    int i, j;
    scanf("%d", &t);
    for(z = 1; z <= t; z++){
        scanf("%d%d%d", &n, &m, &k);
        memset(&A, 0, sizeof(A));
        priority_queue<Point> pq;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++){
                scanf("%d", &A[i+IDX][j+IDX]);
                if(A[i+IDX][j+IDX]) pq.push({i+IDX, j+IDX, A[i+IDX][j+IDX]+1, A[i+IDX][j+IDX]});
            }
        for(int hour = 1; hour <= k; hour++){
            while(!pq.empty() && pq.top().act <= hour){
                int y = pq.top().y, x = pq.top().x, age = pq.top().age;
                pq.pop();
                if(age == -1) continue;
                if(age > 1) pq.push({y,x,hour+age-1,-1});
                for(i = 0; i < 4; i++){
                    int ny = y+D[i][0], nx = x+D[i][1];
                    if(A[ny][nx]) continue;
                    A[ny][nx] = age;
                    pq.push({ny, nx, hour+age+1, age});
                }
            }
        }
        printf("#%d %d\n", z, (int)pq.size());
    }
}