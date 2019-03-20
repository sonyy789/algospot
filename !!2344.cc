#include <cstdio>
#include <vector>
#include <map>
using namespace std;
struct Point{
    int y, x;
    bool operator<(const Point &P) const{
        return (y==P.y)?(x<P.x):(y<P.y);
    }
};
int n, m;
int A[1001][1001];
int D[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int main(){
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            scanf("%d", &A[i][j]);
    map<Point, int> mp;        
    vector<pair<Point, int>> B;
    int cnt = 0;
    for(i = 1; i <= n; i++) mp[{i,0}] = ++cnt, B.push_back({{i,1},0});
    for(j = 1; j <= m; j++) mp[{n+1,j}] = ++cnt, B.push_back({{n,j},1});
    for(i = n; i >= 1; i--) mp[{i,m+1}] = ++cnt, B.push_back({{i,m},2});
    for(j = m; j >= 1; j--) mp[{0,j}] = ++cnt, B.push_back({{1,j},3});
    for(i = 0; i < B.size(); i++){
        int y = B[i].first.y;
        int x = B[i].first.x;
        int dir = B[i].second;
        while(x > 0 && x <= m && y > 0 && y <= n){
            if(A[y][x]){ 
                if(dir&1) dir = (dir+3)%4;
                else dir = (dir+1)%4;
            }
            y += D[dir][0], x += D[dir][1];
        }
        printf("%d ", mp[{y,x}]);
    }
}