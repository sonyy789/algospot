#include <cstdio>
#include <algorithm>
using namespace std;
struct POINT{
    int x, y;
    bool operator <(const POINT &A)const{
        return x == A.x?y<A.y:x<A.x;
    }
};
POINT A,B,R[4];
int ccw(POINT P1, POINT P2, POINT P3){
    int t = P1.x*P2.y+P2.x*P3.y+P3.x*P1.y-P1.y*P2.x-P2.y*P3.x-P3.y*P1.x;
    return t<0?-1:t>0;
}
bool isCross(int idx1, int idx2){
    int ab = ccw(A,B,R[idx1])*ccw(A,B,R[idx2]);
    int cd = ccw(R[idx1], R[idx2], A)*ccw(R[idx1],R[idx2], B);
    if(ab == 0 && cd == 0){
        pair<POINT, POINT> P1, P2;
        if(A<B) P1 = {A,B};
        else P1 = {B,A};
        if(R[idx1]<R[idx2]) P2 = {R[idx1],R[idx2]};
        else P2 = {R[idx2],R[idx1]};
        if((P1.first < P2.first && P1.second < P2.first)||(P2.first < P1.first && P2.second < P1.first)) return false;
    }
    return ab<=0&&cd<=0;
}
void swap(POINT &P1, POINT &P2){
    POINT T;
    T.y = P1.y; T.x = P1.x;
    P1.y = P2.y, P1.x = P2.x;
    P2.y = T.y, P2.x = T.x;
}
int main(){
    int t, minY, maxY, minX, maxX;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d%d%d%d",&A.x, &A.y,&B.x, &B.y, &R[0].x, &R[0].y,&R[2].x, &R[2].y);
        if(R[0].y < R[2].y) swap(R[0], R[2]);
        maxY = R[0].y; minY = R[2].y;
        if(R[0].x > R[2].x){
            maxX = R[0].x, minX = R[2].x;
            R[1] = {maxX, minY}; R[3] = {minX, maxY};
        }else{
            maxX = R[2].x, minX = R[0].x;
            R[1] = {maxX, maxY}; R[3] = {minX, minY};
        }
        if(A.y < maxY && B.y < maxY && A.y > minY && B.y > minY && A.x < maxX && B.x < maxX && A.x > minX && B.x > minX) {printf("T\n"); continue;}
        int f = 1;
        for(int i = 0; i < 4; i++)
            if(isCross(i, (i+1)%4)) {f=0; break;}
        if(f) printf("F\n");
        else printf("T\n");
    }
}