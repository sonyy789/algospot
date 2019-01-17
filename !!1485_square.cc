#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct Point{
    long long int y,x;
};
Point P[4];
double D[6];
double dist(int a, int b){ return (double)sqrt((P[a].x-P[b].x)*(P[a].x-P[b].x)+(P[a].y-P[b].y)*(P[a].y-P[b].y));}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int idx = 0;
        for(int i = 0; i < 4; i++) scanf("%lld%lld",&P[i].x, &P[i].y);
        for(int i = 0; i < 3; i++)
            for(int j = i+1; j < 4; j++)
                D[idx++] = dist(i,j);
        
        double cVal = 0, vVal = 1e9;
        for(int i = 0; i < 6; i++){
            cVal = max(cVal, D[i]);
            vVal = min(vVal, D[i]);
        }
        int vCnt = 0, cCnt = 0;
        for(int i = 0; i < 6; i++){
            vCnt += D[i]==vVal;
            cCnt += D[i]==cVal;
        }
        if(cCnt == 2 && vCnt == 4) printf("1\n");
        else printf("0\n");
    }
}