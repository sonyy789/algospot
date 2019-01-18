#include <cstdio>
#include <algorithm>
using namespace std;
struct Point{
    int x, y;
    bool operator <(const Point &A)const{
        return x==A.x?y<A.y:x<A.x;
    }
}P[2][101];
int upChain[101], downChain[101];
int convex[2][101], cxIdx[2];
int ucIdx, dcIdx;
int t, n, m;
void swap(Point &A, Point &B){
    Point T = A;
    A = B;
    B = T;
}
int ccw(int a, int b, int c, int idx){
    int t = P[idx][a].x*P[idx][b].y+P[idx][b].x*P[idx][c].y+P[idx][c].x*P[idx][a].y;
    t -= (P[idx][a].y*P[idx][b].x+P[idx][b].y*P[idx][c].x+P[idx][c].y*P[idx][a].x);
    return t<0?-1:t>0;
}
int ccw(Point A, Point B, Point C){
    int t = A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
    return t<0?-1:t>0;
}
bool isCross(Point A, Point B, Point C, Point D){
    int ab = ccw(A, B, C)*ccw(A, B, D);
    int cd = ccw(C, D, A)*ccw(C, D, B);
    if(ab == 0 && cd == 0){
        if(B < A) swap(A,B);
        if(D < C) swap(C,D);
        if((A < C && B < C)||(C < A && D < A)) return false;
    }
    return ab<=0 && cd<=0;
}
void convexHull(int idx, int size){
    sort(P[idx]+1, P[idx]+size+1);
    for(int i = 1; i <= size; i++){
        while(ucIdx > 1 && ccw(upChain[ucIdx-1], upChain[ucIdx], i, idx) >= 0){
            ucIdx--;
        }
        upChain[++ucIdx] = i;
    }
    for(int i = size; i >= 1; i--){
        while(dcIdx > 1 && ccw(downChain[dcIdx-1], downChain[dcIdx], i, idx) >= 0){
            dcIdx--;
        }
        downChain[++dcIdx] = i;
    }
    for(int i = 1; i <= ucIdx; i++) convex[idx][++cxIdx[idx]] = upChain[i];
    for(int i = 2; i <  dcIdx; i++) convex[idx][++cxIdx[idx]] = downChain[i];
    return;
}
int main(){
    scanf("%d", &t);
    while(t--){
        cxIdx[0] = cxIdx[1] = 0;
        scanf("%d%d", &n, &m); 
        for(int i= 1; i <= n; i++) scanf("%d%d", &P[0][i].x, &P[0][i].y);
        for(int i= 1; i <= m; i++) scanf("%d%d", &P[1][i].x, &P[1][i].y);
        if(n==1) P[0][2] = P[0][1];
        if(m==1) P[1][2] = P[1][1];
        convexHull(0, n); ucIdx = dcIdx = 0;
        convexHull(1, m); ucIdx = dcIdx = 0;
        Point A,B,C,D;
        
        convex[0][0] = convex[0][cxIdx[0]];
        convex[1][0] = convex[1][cxIdx[1]];
        if(cxIdx[0] == 2) cxIdx[0]--;
        if(cxIdx[1] == 2) cxIdx[1]--;
        bool flag = true; 
        for(int i = 0; i < cxIdx[0]; i++){
            A = P[0][convex[0][i]]; B = P[0][convex[0][i+1]];
            for(int j = 0; j < cxIdx[1]; j++){
                C = P[1][convex[1][j]]; D = P[1][convex[1][j+1]];
                if(isCross(A, B, C, D)) {flag = false; i+= cxIdx[0], j += cxIdx[1];}
            }
        }
        for(int i = 0; i < 2; i++){
            Point inf = {10001, P[i][1].y+1};
            int cross = 0;
            for(int j = 0; j < cxIdx[(i+1)%2]; j++){
                A = P[(i+1)%2][convex[(i+1)%2][j]]; B = P[(i+1)%2][convex[(i+1)%2][j+1]];
                if(isCross(A, B, P[i][1], inf)) cross++;
            }
            if(cross%2 && cxIdx[(i+1)%2] != 1) {flag = false; i+=2;}
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}