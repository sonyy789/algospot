#include <cstdio>
using namespace std;
int n;
int D[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool visit[31][31];
double P[4];
double solve(int y, int x, int depth){
    if(depth == n) return 1;
    double ret = 0;
    int i;
    visit[y][x] = true;
    for(i = 0; i < 4; i++){
        int ny = y+D[i][0], nx = x+D[i][1];
        if(visit[ny][nx]) continue;
        ret += solve(ny,nx,depth+1)*P[i];
    }
    visit[y][x] = false;
    return ret;
}
int main(){
    int i;
    scanf("%d", &n);
    for(i = 0; i < 4; i++){
        scanf("%lf", P+i);
        P[i] /= 100;
    }
    printf("%.9lf",solve(15, 15, 0));
}