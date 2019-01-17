#include <cstdio>
#include <algorithm>
using namespace std;
struct Point{ 
    int x,y;
    bool operator <(const Point &A)const{
        return x==A.x?y<A.y:x<A.x;
    }
};
struct Line{ Point P1, P2; };
Line L[3001];
int R[3001], C[3001];
void swap(Point &P1, Point &P2){
    Point T;
    T.y = P1.y, T.x = P1.x;
    P1.y = P2.y, P1.x = P2.x;
    P2.y = T.y, P2.x = T.x;
}
int ccw(Point A, Point B, Point C){
    int t = A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
    return t<0?-1:t>0;
}
bool isCross(Line A, Line B){
    int ab = ccw(A.P1, A.P2, B.P1)*ccw(A.P1, A.P2, B.P2);
    int cd = ccw(B.P1, B.P2, A.P1)*ccw(B.P1, B.P2, A.P2);
    if(ab == 0 && cd == 0){
        if(A.P2 < A.P1) swap(A.P1, A.P2);
        if(B.P2 < B.P1) swap(B.P1, B.P2);
        if((A.P1 < B.P1 && A.P2 < B.P1)||(B.P1 < A.P1 && B.P2 < A.P1)) return false;
    }
    return ab<=0&&cd<=0;
}
int find(int a){
    if(R[a] == a) return a;
    return R[a] = find(R[a]);
}
void merge(int a, int b){
    a = find(a); b = find(b);
    if(a != b) R[b] = a;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i= 1; i <= n; i++){
        scanf("%d%d%d%d", &L[i].P1.x, &L[i].P1.y, &L[i].P2.x, &L[i].P2.y);
        R[i] = i;
    }
    for(int i = 1; i < n; i++)
        for(int j = i+1; j <= n; j++)
            if(isCross(L[i], L[j])) merge(i, j);

    for(int i = 1; i <= n; i++) C[find(i)]++;
    int gCnt = 0, maxCnt = 0;
    for(int i = 1; i <= n; i++){
        if(C[i]){
            gCnt++;
            if(maxCnt < C[i]) maxCnt = C[i];
        }
    }
    printf("%d\n%d",gCnt, maxCnt);
}