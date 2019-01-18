#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int lld;
int n;
struct Point {
    lld x,y;
    bool operator <(const Point &A)const{
        return x==A.x?y<A.y:x<A.x;
    }
}P[100001];
int upChain[100001], downChain[100001];
int ucIdx, dcIdx;
int ccw(int a, int b, int c){
    lld t = P[a].x*P[b].y+P[b].x*P[c].y+P[c].x*P[a].y-P[a].y*P[b].x-P[b].y*P[c].x-P[c].y*P[a].x;
    return t<0?-1:t>0;
}
int convexHull(){
    sort(P+1, P+n+1);
    for(int i = 1; i <= n; i++){
        while(ucIdx > 1 && ccw(upChain[ucIdx-1],upChain[ucIdx], i)>=0){
            ucIdx--;
        }
        upChain[++ucIdx] = i;
    }
    for(int i= n; i >= 1; i--){
        while(dcIdx > 1 && ccw(downChain[dcIdx-1],downChain[dcIdx], i) >=0){
            dcIdx--;
        }
        downChain[++dcIdx] = i;
    }
    return ucIdx+dcIdx-2;
}
int main(){
    scanf("%d", &n);
    for(int i= 1; i <= n; i++)
        scanf("%lld%lld", &P[i].x, &P[i].y);
    printf("%d", convexHull());
}