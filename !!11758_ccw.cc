#include <cstdio>
struct Point{
    int x, y;
};
int ccw(Point A, Point B, Point C){
    int t = A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
    return t < 0 ? -1: t > 0;
}
int main(){
    Point P[3];
    for(int i = 0; i < 3; i++)
        scanf("%d%d", &P[i].x, &P[i].y);
    int dy = P[0].y-P[1].y, dx = P[0].x-P[1].x;
    P[2].y -= (dy+P[0].y), P[2].x -= (dx+P[0].x;
    P[1].y -= P[0].y, P[1].x -= P[0].x;
    P[0].y = 0, P[0].x = 0;
    printf("%d", ccw(P[0], P[1], P[2]));
}