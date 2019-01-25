#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
struct Point{
    int x, y;
};
bool visit[102];
Point P[102];
int t, n, i, y, x;

int main(){
    scanf("%d", &t);
    while(t--){
        for(i = 0; i < 102; i++) visit[i] = false;
        scanf("%d", &n);
        for(i = 0; i <= n+1; i++)
            scanf("%d%d", &P[i].x, &P[i].y);
        queue<Point> q;
        q.push(P[0]);
        while(!q.empty()){
            y = q.front().y;
            x = q.front().x;
            q.pop();
            for(i = 1; i <= n+1; i++){
                if( visit[i] || (abs(y-P[i].y)+abs(x-P[i].x)) > 1000) continue;
                q.push(P[i]);
                visit[i] = true;
            }
        }
        if(visit[n+1]) printf("happy\n");
        else printf("sad\n");
    }
}